#include"cmd.h"
#include"interface.h"
#include"information.h"
#include<regex>
#include<string>
#include<iostream>
#include<fstream>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>
using namespace std;



void analy_cmd(string input){
    string cmd;
    string option;
    string argument;
    string argument_app;
    regex pattern("([a-zA-Z]+) ?(-[a-zA-Z])? ?(\\S+)? ?(\\S+)?");
	smatch result;
	bool ismatch = regex_search(input, result, pattern);
    if(ismatch){
        cmd=result[1];
        option=result[2];
        argument=result[3];
        argument_app=result[4];
        do_cmd(input,cmd,option,argument,argument_app);
    }
    else input_error(input);
    return;
}

void do_cmd(string input,string cmd,string option,string argument,string argument_app){
    if(cmd=="quit"||cmd=="layout"||cmd=="exit")cmd_quit();
    else if(cmd=="wc")analy_cmd_wc(option,argument);
    else if(cmd=="cmp")analy_cmd_cmp(argument,argument_app);
    else if(cmd=="cat")analy_cmd_cat(option,argument);
    else if(cmd=="cp")analy_cmd_cp(option,argument,argument_app);
    else if(cmd=="pwd")cmd_pwd();
    else if(cmd=="echo")cmd_echo(argument);
    else input_error(input);
    return;
}

void cmd_echo(string argument){
    cout<<argument<<endl;
}

void cmd_pwd(){
    char* a=new char[1000];
    getcwd(a,1000);
    cout<<a<<endl;
    return;
}

void cmd_quit(){
    cout<<"Successful to quit\n";
    exit(0);
}


void analy_cmd_wc(string option,string argument){
    if(option=="-c"){
        cmd_wc_c(argument);
    }
    else if(option=="-w"){
        cmd_wc_w(argument);
    }
    else if(option=="-l"){
        cmd_wc_l(argument);
    }
    else {
        cout<<"No such command:"<<option<<endl;
        cout<<"Do you mean \'wc -c "<<argument<<"\'"<<endl;
        cout<<"         or \'wc -w "<<argument<<"\'"<<endl;
        cout<<"         or \'wc -l "<<argument<<"\'"<<endl;
    }
    return;    
}

void cmd_wc_c(string argument){
    vector<string> content=readtxt(argument);
    if(content.empty()){cout<<"The file can't be opened\n";return;}
    int count=coun_byte(content);
    cout<<count<<" "<<argument<<endl;
    return;
}
void cmd_wc_w(string argument){
    vector<string> content=readtxt(argument);
    if(content.empty()){cout<<"The file can't be opened\n";return;}
    int count=coun_words(content);
    cout<<count<<" "<<argument<<endl;
    return;
}
void cmd_wc_l(string argument){
    vector<string> content=readtxt(argument);
    if(content.empty()){cout<<"The file can't be opened\n";return;}
    int count=coun_lines(content);
    cout<<count<<" "<<argument<<endl;
    return;
}

void analy_cmd_cmp(string argument,string argument_app){
    if(argument_app.empty()||argument_app.empty()){cout<<"File open failed!"<<endl;return;}
    else cmd_cmp(argument,argument_app);
    return;
}
void cmd_cmp(string argument,string argument_app){
    vector<string> file1;
    vector<string> file2;
    file1=readtxt(argument);
    file2=readtxt(argument_app);
    int equal=cmp_string(argument,argument_app,file1,file2);
    return;
}

void analy_cmd_cat(string option,string argument){
    if(option!="-E"&&option!="-b"&&option!="-s"&&option!="-n"&&!option.empty()){
        cout<<"cat: invalid option -- \'"<<option<<"\'\nTry \'cat --help\' for more information.\n";
        return;
    }
    struct stat path;
    if(argument.empty()){cout<< "what do you want to cat?"<<endl;return;}
    stat(argument.c_str(), &path);
    if (S_ISDIR(path.st_mode)) 
        cout << "cat: " << argument << ": Is a directory" << endl;
    ifstream file(argument);
    if(file.is_open()){
        file.close(); 
        cmd_cat(option,argument);
    }
    else 
        cout << "cat: " << argument << ": No such file or directory" << endl;
    return;
}
void cmd_cat(string option,string argument){
    vector<string> content;
    content=readtxt(argument);
    int num=0;
    for(int i=0;i<content.size();i++){
        if (option=="-s"){
            if(i!=0){
                if(check_blank(content[i])&&check_blank(content[i-1]))continue;
            }
        }
        else if (option=="-b"&&!check_blank(content[i])) cout << ++num << " ";
        else if (option=="-n") cout << ++num << " ";
        cout << content[i];
        if (option=="-E") cout << "$";
        cout << endl;
    }
    return;
}
bool check_blank(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]!=' '&&s[i]!='\t')return false;
    }
    return true;
}


void cmd_copy_file(string option,string argument, string argument_app) {
    ifstream in;
    in.open(argument, ios::in | ios::binary);
    if (in.is_open()) {
        ifstream fout;
        fout.open(argument_app, ios::out | ios::binary);
        if (fout.is_open()) {
            if (option=="-i") {
                cout << "cp: overwrite \'"<<argument_app << "\'? ";
                char ans;
                ans=getchar();
                if (!(ans=='Y'||ans=='y')){ans=getchar();fout.close();return;}
                ans=getchar();
            }
            fout.close();
        }
        in.close();
        copy_file(argument, argument_app);
    }
    else cout << "cp: cannot stat \'"<<argument<<"\': No such file or directory" << endl;
}


void analy_cmd_cp(string option,string argument,string argument_app){
    if(option!="-i"&&option!="-r"&&!option.empty()){
        cout<<"cp: invalid option -- \'c\'"<<option<<"\nTry \'cp --help\' for more information.\n";
    }
    struct stat judge1;
    struct stat judge2;
    stat(argument.c_str(),&judge1);
    stat(argument_app.c_str(),&judge2);
    if(S_ISDIR(judge1.st_mode) && S_ISDIR(judge2.st_mode)){//如果两个参数都是文件夹
        if(option=="-r"){
            string dirname=get_cur_name(argument);//获得要拷贝的文件夹名字
            string main=argument_app+"/"+dirname;//要创建的外层文件夹名字
            int a=mkdir(main.c_str(),0755);//创建文件夹
            if(a!=0){cout<<"can't make direct"<<endl;return;}
            cmd_cp_directory(argument,main);
        }
        else cout<<"cp: -r not specified; omitting directory \'"<<argument<<"\'"<<endl;
        return;
    }
    else if(S_ISREG(judge1.st_mode) && S_ISREG(judge2.st_mode)){
        cmd_copy_file(option,argument,argument_app);
        return;
    }
    else if(S_ISDIR(judge1.st_mode) && S_ISREG(judge2.st_mode)){
        if(option=="-r")cout<<"cp: cannot overwrite non-directory \'"<<argument_app<<"\' with directory \'"<<argument<<endl;
        else cout<<"cp: -r not specified; omitting directory \'"<<argument<<"\'"<<endl;
        return;
    }
    else if(S_ISREG(judge1.st_mode) && S_ISDIR(judge2.st_mode)){
        string filename=get_cur_name(argument);
        string dest=argument_app+"/"+filename;
        cmd_copy_file(option,argument,dest);
        return;
    }
    else if(!S_ISREG(judge1.st_mode) && !S_ISDIR(judge1.st_mode)){
        cout<<"cp: cannot stat \'"<<argument<<"\': No such file or directory";
        return;
    }
    else if(S_ISREG(judge1.st_mode)){
        cmd_copy_file(option,argument,argument_app);
        return;
    }
    return;
}




void cmd_cp_directory(string argument, string argument_app) {
    DIR* direct;
    direct=opendir(argument.c_str());
    if (NULL!=direct) {
        dirent* subdirect=readdir(direct);
        while(subdirect!=NULL) {
            //如果是目录
            int a1=strcmp(subdirect->d_name,".");
            int a2=strcmp(subdirect->d_name,"..");
            if (subdirect->d_type == DT_DIR&& a1!=0&&a2!=0 ) {
                string s(1, '/');
                string old_sub_dir = argument + s + subdirect->d_name;//当前子目录名字
                string dest_sub_dir = argument_app + s + subdirect->d_name;//目标子目录名字
                DIR* new_dir;//如果没有目标子目录就建一个
                if (NULL==(new_dir=opendir(dest_sub_dir.c_str()))){
                    int a=mkdir(dest_sub_dir.c_str(),0755);
                    if(a!=0){cout<<"can't make a directory"<<endl;return;}
                }
                cmd_cp_directory(old_sub_dir,dest_sub_dir);//对子目录递归
            }
            //如果是文件
            else if (subdirect->d_type == DT_REG) {
                string s(1, '/');
                string file1 = argument + s + subdirect->d_name;
                string file2 = argument_app + s + subdirect->d_name;
                copy_file( file1, file2);
            }
            subdirect = readdir(direct);
        }
    }
    //打不开的情况
    else cout << "cp: cannot stat \'"<<argument<< "\': No such file or directory" << endl;
    closedir(direct);
}
