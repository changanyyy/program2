#include"cmd.h"
#include"interface.h"
#include<regex>
#include<string>
#include<iostream>
using namespace std;


void analy_cmd(string input){
    string cmd;
    string option;
    string argument;
    regex pattern("([a-zA-Z]+) ?(-[a-z])? ?(.*)?");
	smatch result;
	bool ismatch = regex_search(input, result, pattern);
    if(ismatch){
        cmd=result[1];
        option=result[2];
        argument=result[3];
        do_cmd(cmd,option,argument);
    }
    else input_error(input);
    return;
}

void do_cmd(string cmd,string option,string argument){
    if(cmd=="quit"||cmd=="layout"||cmd=="exit")cmd_quit();
    else input_error(cmd);
    return;
}



void cmd_quit(){
    cout<<"Successful to quit\n";
    exit(0);
}