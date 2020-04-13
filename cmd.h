#ifndef _CMD_H
#define _CMD_H
#include<string>
using namespace std;


void analy_cmd(string input);

void do_cmd(string input,string cmd,string option,string argument,string argument_app);

void cmd_quit();

void cmd_pwd();

void analy_cmd_wc(string option,string argument);
int cmd_wc_c(string argument);
int cmd_wc_w(string argument);
int cmd_wc_l(string argument);

void analy_cmd_cmp(string argument,string argument_app);
void cmd_cmp(string argument,string argument_app);
string readfile_cmp(string argument);

void analy_cmd_cat(string option,string arguement);
void cmd_cat(string option,string argument);
bool check_blank(string s);

void analy_cmd_cp(string option,string argument,string argument_app);
void cmd_copy_file(string option,string argument, string argument_app);
void cmd_cp_directory(string argument, string argument_app);

void cmd_echo(string argument);

void analy_cmd_mkdir(string option,string argument);
void cmd_mkdir(string argument);

void analy_cmd_ls(string option,string argument);
void cmd_ls(string option,string argument);


#endif !_CMD_H