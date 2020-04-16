#include<iostream>
#include"interface.h"
#include"cmd.h"
#include<string>
#include<unistd.h>


using namespace std;
void print_prompt(){
    char* a=new char[1000];
    getcwd(a,1000);
    cout<<"\033[32mxizhe";
    cout<<"@MyShell:\033[34m"<<a<<"$ \033[0m";
    return ;
}



string get_inputs(){
    string input;	
    getline(cin,input);
    //设置最长上限是100
    if( input.size()> 100) {		
        cout<<"command is too long \n";		
        exit(-1); 
    } 	
    return input;   
}

void input_error(string input){
    if(input.empty())return;
    cout<<input<<":command not found\n";
    return ;
}


void printfile(vector<string> content){
    for(int i=0;i<content.size();i++){
        cout<<content[i]<<endl;
    }
    return;
}

void man_wc(){
    string option;
    cmd_cat(option,"wc.txt");
    return;
}
void man_cmp(){
    string option;
    cmd_cat(option,"cmp.txt");
    return;
}
void man_cat(){
    string option;
    cmd_cat(option,"cat.txt");
    return;
}
void man_cp(){
    string option;
    cmd_cat(option,"cp.txt");
    return;
}
void man_pwd(){
    string option;
    cmd_cat(option,"pwd.txt");
    return;
}
void man_echo(){
    string option;
    cmd_cat(option,"echo.txt");
    return;
}
void man_ls(){
    string option;
    cmd_cat(option,"ls.txt");
    return;
}
void man_mkdir(){
    string option;
    cmd_cat(option,"mkdir.txt");
    return;
}
void man_cd(){
    string option;
    cmd_cat(option,"cd.txt");
    return;
}
void man_man(){
    string option;
    cmd_cat(option,"man.txt");
    return;
}
