#ifndef _CMD_H
#define _CMD_H
#include<string>
using namespace std;


void analy_cmd(string input);

void do_cmd(string cmd,string option,string argument,string argument_app);

void cmd_quit();

void analy_cmd_wc(string option,string argument);
void cmd_wc_c(string argument);
void cmd_wc_w(string argument);
void cmd_wc_l(string argument);

void analy_cmd_cmp(string argument,string argument_app);
void cmd_cmp(string argument,string argument_app);


#endif !_CMD_H