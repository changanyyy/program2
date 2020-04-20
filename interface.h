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

void man_wc();
void man_cmp();
void man_cat();
void man_cp();
void man_pwd();
void man_echo();
void man_ls();
void man_mkdir();
void man_cd();
void man_man();
void man_sh();



#endif !_INTERFACE_H
