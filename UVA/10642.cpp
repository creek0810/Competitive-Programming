#include <stdio.h>
long int abs(long int num){
	if(num<0){
		return num*(-1);
	}else{
		return num;
	}	
}
int main(){
	int cases;
	int times=1;
	scanf("%d",&cases);
	while(cases--){
		long int x[2],y[2];
		long long int dis[2]={0};
		for(int i=0;i<2;i++){
			scanf("%ld",&x[i]);
			scanf("%ld",&y[i]);
		}
		for(int i=0;i<2;i++){
			long int tmp;
			tmp=x[i]+y[i];
			if(tmp==0){
				dis[i]=0;
			}else if(tmp==1){
				dis[i]=tmp+x[i];
			}else if(tmp==2){
				dis[i]=tmp+x[i]+1;
			}else{
				dis[i]=((tmp-1)*(2+tmp))/2;
				//printf("%ld %ld %ld\n",(tmp-1),(2+tmp)*(tmp-1),(2+tmp));
				dis[i]+=x[i]+1;
			}

		}
		printf("Case %d: %ld\n",times,abs(dis[0]-dis[1]));
		times++;
	}
	return 0;
}