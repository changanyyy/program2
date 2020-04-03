#include"information.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

vector<string> readtxt(string filename){
    vector<string> content;
    ifstream fin;
    fin.open(filename,ios::in);
    if(!fin.is_open()){cout<<filename<<"can't be opened"<<endl ; return content ; }//返回空向量
    while(fin.eof()){
        string temp;
        getline(cin,temp);
        content.push_back(temp);
    }
    fin.close();
    return content;//返回string向量
}

void writetxt(string filename,vector<string> content){
    ofstream fout;
    fout.open(filename,ios::trunc);
    if(!fout.is_open()){cout<<filename<<"can't be opened"<<endl ; return ;}
    for(auto it=content.begin();it!=content.end();it++){
        cout<<*it<<endl;
    }
    return;
}