#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	long long int n,m;
	while(scanf("%lld",&n)!=EOF){
		scanf("%lld",&m);
		if(m==0 && n==0){
			break;
		}
		vector<long long int>table;
		table.resize(n);
		for(long long int i=0;i<n;i++){
			scanf("%lld",&table[i]);
		}
		sort(table.begin(),table.end());
		long long int count = 0,loc = 0;
		for(long long int i=0;i<m;i++){
			long long int tmp;
			scanf("%lld",&tmp);
			while(loc<n && table[loc]<tmp){
				loc++;
			}
			if(table[loc] == tmp){
				count++;
				loc++;
			}
		}
		printf("%lld\n",count);
	}
}