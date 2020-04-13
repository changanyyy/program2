#include"information.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
using namespace std;

vector<string> readtxt(string filename){
    vector<string> content;
    ifstream fin;
    fin.open(filename,ios::in);
    if(!fin){cout<<filename<<": No such file or directory"<<endl ; return content ; }//返回空向量
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
    if(!fout){printf("%s  can't be opened\n",filename.c_str()) ; return ;}
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


int cmp_string(string filename1,string filename2,string a, string b) {
    vector<string> s1=readtxt(filename1);
    vector<string> s2=readtxt(filename2);
    int size1=0,size2=0;
    for(int i=0;i<s1.size();i++){
        size1+=s1[i].size();
    }
     for(int i=0;i<s2.size();i++){
        size2+=s2[i].size();
    }
    int min_size=min(a.size(),b.size());
    int line=0;
    int i;
    for(i=0;i<min_size;i++){
        if(a[i]!=b[i]){
            cout<<filename1<<" "<<filename2<<" differ: byte "<<i+1<<" line "<<line+1<<endl;
            return -1;
        }
        if(a[i]=='\n'){
            line++;
        }
    }
    if(size1!=size2){
        if(size1>size2){cout<<"cmp: EOF on "<<filename2<<" after byte "<<i<<", in line"<<line+1<<endl;return -1;}
        else if(size1<size2){cout<<"cmp: EOF on "<<filename1<<" after byte "<<i<<", in line"<<line+1<<endl;return -1;}
    }
    return 0;
}

void copy_file(string argument, string argument_app) {
    ifstream in;
    in.open(argument, ios::in | ios::binary);
    in.seekg(0, ios::end);
    int size = in.tellg();
    char* content = new char[size + 1];
    in.seekg(0, ios::beg);
    in.read(content, size);
    in.close();
    ofstream out;
    out.open(argument_app, ios::out | ios::binary);
    if (out.is_open()) { out.write(content, size); out.close(); }
    else cout << "Copy file failed" << endl;
    return;
}



string get_cur_name(string argument) {
    string file_name;
    int i = argument.size() - 1;
    while (i != -1 && argument[i] != '/') {
        file_name.push_back(argument[i--]);
    }
    reverse(file_name.begin(), file_name.end());
    return file_name;
}