#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef struct{
	char alp;
	int num;
}inf;
bool cmp(inf a,inf b){
	if(a.num==b.num){
		return a.alp>b.alp;
	}
	return a.num<b.num;
}
int main(){
	char str[1005]={0};
	bool first=true;
	while(gets(str)){
		if(first==false){
			printf("\n");
		}else{
			first=false;
		}
		vector<inf>table;
		for(int i=0;i<strlen(str);i++){
			bool find=false;
			for(int k=0;k<table.size();k++){
				if(str[i]==table[k].alp){
					table[k].num++;
					find=true;
					break;
				}
			}
			if(find==false){
				table.push_back((inf){str[i],1});
			}
		}
		sort(table.begin(),table.end(),cmp);
		for(int i=0;i<table.size();i++){
			printf("%d %d\n",table[i].alp,table[i].num);
		}
	}
}