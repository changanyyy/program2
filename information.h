#ifndef _INFORMATION_H
#define _INFORMATION_H
#include<vector>
#include<string>
using namespace std;


vector<string> readtxt(string filename);

void writetxt(string filename,vector<string> content);


int coun_byte(vector<string> content);
int coun_words(vector<string> content);
int coun_lines(vector<string> content);

int cmp_string(string filename1,string filename2,vector<string> a,vector<string> b);

#endif !_INFORMATION_H