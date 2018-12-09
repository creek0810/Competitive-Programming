#include <stdio.h>
int main(){
	int cases;
	scanf("%d",&cases);
	while(cases--){
		int sum,dif;
		scanf("%d %d",&sum,&dif);
		if(sum<dif || (sum+dif)%2==1){
			printf("impossible\n");
		}else{
			printf("%d %d\n",(sum+dif)/2,sum-(sum+dif)/2);
		}
	}
	return 0;
}