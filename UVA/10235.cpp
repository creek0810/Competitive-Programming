#include <stdio.h>
#include <math.h>
int main(){
	long long int num;
	while(scanf("%lld",&num)!=EOF){
		long long int reverse=0;
		bool flag=false;
		for(int i=2;i<=sqrt(num);i++){
			if(num%i==0){
				flag =true;
				break;
			}
		}
		if(flag==true){
			printf("%lld is not prime.\n",num);
		}else{
			long long int tmp;
			tmp =num;
			while(tmp!=0){
				reverse*=10;
				reverse+=tmp%10;
				tmp/=10;
			}
			for(int i=2;i<=sqrt(reverse);i++){
				if(reverse%i==0){
					flag =true;
					break;
				}
			}
			if(reverse==num || flag==true){
				printf("%lld is prime.\n",num);
			}else{
				printf("%lld is emirp.\n",num);
			}
		}
	}
	return 0;
}