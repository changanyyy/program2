#include<iostream>
#include<string>
#include"interface.h"
#include"cmd.h"
#include"information.h"
using namespace std;

int main(){
	vector<string> a;
	string fn1="a.txt";
	string fn2="b.txt";
	a=readtxt(fn1);
	writetxt(fn2,a);

	while(true){
		string input;
		print_prompt();
		input=get_inputs();
		analy_cmd(input);
	}
	return 0;
}