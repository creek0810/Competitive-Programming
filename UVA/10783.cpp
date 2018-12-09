#include <stdio.h>
int main(){
	int cases;
	scanf(" %d",&cases);
	for(int i=1;i<=cases;i++){
		int begin,end;
		int sum=0;
		scanf(" %d %d",&begin,&end);
		if(begin%2==0){
			begin++;
		}
		for(int z=begin;z<=end;z=z+2){
			sum+=z;
		}
		printf("Case %d: %d\n",i,sum);
	}
	return 0;
}