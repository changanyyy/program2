#include"cmd.h"
#include"interface.h"
#include"information.h"
#include<regex>
#include<string>
#include<iostream>
using namespace std;


void analy_cmd(string input){
    string cmd;
    string option;
    string argument;
    string argument_app;
    regex pattern("([a-zA-Z]+) ?(-[a-z])? ?(\\S+)? ?(\\S+)?");
	smatch result;
	bool ismatch = regex_search(input, result, pattern);
    if(ismatch){
        cmd=result[1];
        option=result[2];
        argument=result[3];
        argument_app=result[4];
        do_cmd(cmd,option,argument,argument_app);
    }
    else input_error(input);
    return;
}

void do_cmd(string cmd,string option,string argument,string argument_app){
    if(cmd=="quit"||cmd=="layout"||cmd=="exit")cmd_quit();
    else if(cmd=="wc")analy_cmd_wc(option,argument);
    else if(cmd=="cmp")analy_cmd_cmp(argument,argument_app);
    else input_error(cmd);
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
    cout<<equal;
    return;
}