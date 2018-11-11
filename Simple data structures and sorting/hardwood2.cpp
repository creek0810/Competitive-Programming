#include<iostream>
#include<string>
#include<sstream>
#include<map>
using namespace std;
int main(){
	string tmp;
	int cases;
	getline(cin,tmp);
	stringstream ss1(tmp);
	ss1 >> cases;
	getline(cin,tmp);
	for(int i=0;i<cases;i++){
		map<string,int>table;
		int count=0;
		if(i!=0){
			printf("\n");
		}
		string str;
		while(getline(cin,str)){
			if(str==""){
				break;
			}
			count++;
			table[str] += 1;
		}
		for (map<string,int>::iterator it=table.begin();it!=table.end();it++){
			cout << it->first << " " ;
			printf("%.4lf\n",((it->second)/(double)count)*100);
		}
	}	
}