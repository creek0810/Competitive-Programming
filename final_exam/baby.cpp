#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
struct inf{
	int start,end;
};
bool cmp(inf a,inf b){
	if(a.start == b.start){
		return a.end < b.end;
	}
	return a.start < b.start;
}
int main(){
	int cases;
	cin >> cases;
	cin.ignore(256,'\n');
	cin.ignore(256,'\n');
	while(cases--){
		string str;
		vector<inf>table;
		while(getline(cin,str) && str!=""){
			int a,b;
			stringstream ss(str);
			ss >> a >> b;
			if(a>b){
				int tmp = a;
				a = b;
				b = tmp;
			}
			table.push_back({a,b});
		}
		sort(table.begin(),table.end(),cmp);
		int loc = -1, ans = 0;
		for(int i=0;i<table.size();){
			int far=table[i].end;
			while(i<table.size() && table[i].start<=loc+1){
				far = (far > table[i].end) ? far : table[i].end;
				i++;
			}
			ans +=1;
			loc = far;
			if(loc == 199){
				break;
			}
		}
		cout << ans << endl;
	}
}