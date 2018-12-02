#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct inf{
	int a,b;
};
vector<inf>table;
bool used[10]={0};
void dfs(int step,int num,int tar){
	printf("start");
	if(step == 5){
		bool copy[10] = {0},flag = true;
		memcpy(copy,used,sizeof(bool)*10);
		int tmp = num * tar,count = 0;
		while(tmp > 0){
			copy[num%10] = true;
			tmp /= 10;
			count++;
		}
		if(count > 5){
			return;
		}else{
			for(int i=0;i<10;i++){
				if(copy[i] == false){
					flag = false;
					break;
				}
			}
			if(flag == true){
				table.push_back((inf){tmp,num});
			}
		}
	}else{
		for(int i=0;i<10;i++){
			if(used[i] == false){
				used[i] = true;
				num = num * 10 + i;
				printf("%d\n",num);
				return;
				dfs(step+1,num,tar);
				used[i] = false;
			}
		}
	}
}
void init(){
	for(int i=0;i<10;i++){
		used[i] = false;
	}
	table.clear();
}
int main(){
	int num;
	printf("start");
	while(scanf("%d",&num)!=EOF && num!=0){
		init();
		dfs(0,0,num);
		for(auto it=table.begin();it!=table.end();it++){
			printf("%d %d\n",it->a,it->b);
		}

	}	
	
}