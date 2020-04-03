#include<iostream>
#include"interface.h"
#include"cmd.h"
#include<string>

using namespace std;
void print_prompt(){
    cout<<"MyShell$ ";
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
    cout<<input<<":command not found\n";
    return ;
}