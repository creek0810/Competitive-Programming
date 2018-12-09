#include <cstdio>
#include <queue>
using namespace std;
int main(){
	int cases,times=1;
	while(scanf(" %d",&cases)!=EOF){
		if(cases==0){
			break;
		}
		int table[1000][1000]={0};
		int size[1000]={0};
		for(int i=0;i<cases;i++){
			int num;
			scanf(" %d",&num);
			for(int k=0;k<cases;k++){
				scanf(" %d",&table[i][k]);
			}
		}
		getchar();
		char str[100]={0};
		queue<queue<int>>group;

		while(gets(str)){
			if(str[0]=='S'){
				break;
			}




		}

		printf("Scenario #%d\n",times++);
	}
	return 0;
}