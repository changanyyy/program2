#include<iostream>
#include<string>
#include"interface.h"
#include"cmd.h"
#include"information.h"
using namespace std;

int main(){
	while(true){
		string input;
		print_prompt();
		input=get_inputs();
		analy_cmd(input);
	}
	return 0;
}