#include<cstdio>
#include<vector>
using namespace std;
int num;
void dfs(int step,vector<int>&table,int loc,vector<int>&ans){
	if(step == 6){
		for(int i=0;i<6;i++){
			if(i){
				printf(" ");
			}
			printf("%d",ans[i]);
		}
		printf("\n");
	}else{
		for(int i=loc;i<num-5+step;i++){
			ans[step] = table[i];
			dfs(step+1,table,i+1,ans);
		}
	}
}
int main(){
	bool first = true;
	while(scanf("%d",&num)!=EOF && num!=0){
		vector<int>table(num,0);
		vector<int>ans(6,0);
		for(int i=0;i<num;i++){
			scanf("%d",&table[i]);
		}
		if(first == false){
			printf("\n");
		}
		dfs(0,table,0,ans);
		first = false;
	}
}