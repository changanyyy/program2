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


int cmp_string(string filename1,string filename2,vector<string> a, vector<string> b) {
    int size1 = a.size();
    int size2 = b.size();
    int end=0;
    int min_size=min(size1,size2);
    if (size1 != size2) { end = 1; }
    int line = min(size1, size2);
    for (int i = 0; i < line; i++) {
        int len1 = a[i].size();
        int len2 = b[i].size();
        int max_len = max(len1, len2);
        string app(abs(len1 - len2), '&');
        if (len1 > len2) b[i] += app;
        else if (len1 < len2)a[i] += app;
        for (int j = 0; j < max_len; j++) {
            if (a[i][j] != b[i][j]) {
                cout <<filename1<<" "<<filename2<<" differ: byte " << j+1 << " line " << i+1 << endl;
                return -1;
            }
        }
    }
    if (end == 1)cout <<filename1<<" "<<filename2<<" differ: byte 1 line " << min_size + 1;
    else return 0;
}