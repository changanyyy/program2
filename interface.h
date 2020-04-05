#ifndef _INTERFACE_H
#define _INTERFACE_H
#include<string>
#include<vector>
using namespace std;

//输出交互界面
void print_prompt();	

string get_inputs();

void input_error(string input);

void printfile(vector<string> content);





#endif !_INTERFACE_H
