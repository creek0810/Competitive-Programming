#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int cases;
	scanf("%d",&cases);
	while(cases--){
		int num;
		scanf("%d",&num);
		vector<int>table;
		table.resize(num);
		for(int i=0;i<num;i++){
			scanf("%d",&table[i]);
		}
		long long int count = 0;
		for(int i=0;i<num;i++){
			for(int j=0;j < num-i-1;j++){
				if(table[j] > table[j+1]){
					count++;
					int tmp = table[j];
					table[j] = table[j+1];
					table[j+1] = tmp;
				}
			}
		}
		printf("Optimal train swapping takes %lld swaps.\n",count);
	}
}