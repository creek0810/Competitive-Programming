#include<iostream>
#include<iomanip>
#include<string>
#include<map>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cases;
	bool first = true;
	string tmp;
	cin >> cases;
	cin.ignore(256,'\n');
	getline(cin,tmp);
	while(cases--){
		int count = 0;
		string str;
		map<string,int>table;
		while(getline(cin,str)){
			if(str==""){
				break;
			}
			table[str]+=1;
			count++;
		}
		map<string,int>::iterator it;
		if(first == false){
			cout << "\n";
		}
		for(it=table.begin();it!=table.end();it++){
			cout << it->first << " " << fixed << setprecision(4)<< it->second/(double)count*100 << "\n";
		}
		first = false;
	}
}