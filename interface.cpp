#include<iostream>
#include"interface.h"
#include"cmd.h"
#include<string>
#include<unistd.h>


using namespace std;
void print_prompt(){
    char* a=new char[1000];
    getcwd(a,1000);
    cout<<"xizhe@MyShell:"<<a<<"$";
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