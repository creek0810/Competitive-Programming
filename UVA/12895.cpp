#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	int cases;
	scanf("%d",&cases);
	while(cases--){
		long long int num;
		long long int sum=0;
		long long int tmp=0;
		int len=0;
		scanf("%lld",&num);
		if(num==0){
			printf("Armstrong\n");
			continue;
		}
		tmp=num;
		while(tmp){
			tmp/=10;
			len++;
		}
		tmp=num;
		while(tmp){
			int digit=tmp%10;
			sum+=pow(digit,len);
			tmp/=10;
		}
		if(sum!=num){
			printf("Not ");
		}
		printf("Armstrong\n");
	}
}