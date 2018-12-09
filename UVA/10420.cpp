#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(){
    int cases;
    scanf("%d",&cases);
    getchar();
    map<string,int>table;
    map<string,int>::iterator it;
    while(cases--){
        char name[75]={0};
        gets(name);
        strtok(name," ");
        string tmp(name);
        it=table.find(tmp);
        if(it==table.end()){
            table.insert(pair<string,int>(tmp,1));
        }else{
            it -> second++;
        }
    }
    for(it=table.begin();it!=table.end();it++){
        cout << it -> first << " " <<  it -> second <<endl;
    }

}