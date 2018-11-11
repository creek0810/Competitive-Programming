#include<cstdio>
using namespace std;
int main(){
	int table[]={2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,197,199,311,337,373,719,733,919,971,991,1193,1931,3119,3779,7793,7937,9311,9377,11939,19391,19937,37199,39119,71993,91193,93719,93911,99371,193939,199933,319993,331999,391939,393919,919393,933199,939193,939391,993319,999331};
	int start,end;
	while(scanf("%d",&start)!=EOF && start!=-1){
		scanf("%d",&end);
		int count = 0;
		for(int i=0;i<55;i++){
			if(table[i] >= start && table[i]<=end){
				count++;
			}else if(table[i]>end){
				break;
			}
		}
		if(count == 0){
			printf("No Circular Primes.\n");
		}else if(count == 1){
			printf("1 Circular Prime.\n");
		}else{
			printf("%d Circular Primes.\n",count);
		}

	}	
}