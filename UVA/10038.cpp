#include <stdio.h>
// #include <math.h>
int abs1(int x,int y){
	if((x-y)<0){
		return (x-y)*(-1);
	}else{
		return (x-y);
	}
}
int main(){	
	int cases;
	while(scanf("%d",&cases)!=EOF){
		int table[4000]={0};
		int num[5000]={0};
		int ans=1;
		for(int i=0;i<cases;i++){
			scanf("%d",&num[i]);
		}
		for(int i=0;i<cases-1;i++){
			//printf("%d\n",abs1(num[i],num[i+1]));
			table[abs1(num[i],num[i+1])]=1;
		}
		for(int i=1;i<cases;i++){
			if(table[i]!=1){
				ans=0;
				break;
			}
		}
		if(ans==0){
			printf("Not jolly\n");
		}else{
			printf("Jolly\n");
		}
	}
	return 0;
}