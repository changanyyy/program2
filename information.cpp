#include"information.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

vector<string> readtxt(string filename){
    vector<string> content;
    ifstream fin;
    fin.open(filename,ios::in);
    if(!fin){cout<<filename<<"can't be opened"<<endl ; return content ; }//返回空向量
    while(!fin.eof()){
        string temp;
        getline(fin,temp);
        content.push_back(temp);
    }
    fin.close();
    return content;//返回string向量
}

void writetxt(string filename,vector<string> content){
    ofstream fout;
    fout.open(filename,ios::out);
    if(!fout){printf("%s can't be opened\n",filename.c_str()) ; return ;}
    for(auto it=content.begin();it!=content.end();it++){
        fout<<*it<<endl;
    }
    fout.close();
    return;
}


int coun_byte(vector<string> content){
    int count=0;
    for(auto it=content.begin();it!=content.end();it++){
        count+=(*it).size();
    }
    return count;
}
int coun_words(vector<string> content){
    int count=0;
    for(auto it=content.begin();it!=content.end();it++){
        vector<string> res;
        string temp=*it;
        string result;
        stringstream input(temp);
        while(input>>result)
            res.push_back(result);
        count+=res.size();
        res.clear();
    }
    return count;
}
int coun_lines(vector<string> content){
    return content.size();
}