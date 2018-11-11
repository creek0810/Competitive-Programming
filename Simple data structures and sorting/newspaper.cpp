#include<iostream>
#include<sstream>
#include<iomanip>
#include<map>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cases;
	cin >> cases;
	cin.ignore(256,'\n');
	while(cases--){
		int num;
		long long int ans = 0;
		map<char,int>table;
		cin >> num;
		cin.ignore(256,'\n');
		for(int i=0;i<num;i++){
			int cost;
			string str;
			getline(cin,str);
			char ch = str[0],dontcare;
			stringstream ss(str);
			if(ch == ' '){
				ss >> cost;
			}else{
				ss >> dontcare >> cost;
			}
			table[ch] = cost;
		}
		int line;
		cin >> line;
		cin.ignore(256,'\n');
		for(int i=0;i<line;i++){
			string str;
			getline(cin,str);
			for(int j=0;j<str.size();j++){
				if(table.find(str[j])!=table.end()){
					ans += table[str[j]];
				}
			}
		}
		cout << fixed << setprecision(2) << ans/(double)100 << "$\n";
	}
}