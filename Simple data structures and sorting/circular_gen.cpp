#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
vector<int>prime;
void build_prime(){
	for(int i=2;i<=1000000;i++){
		for(int j=2;j<=sqrt(i);j++){
			if(i%j==0){
				goto end;
			}
		}	
		prime.push_back(i);
		end:;
	}	
}
int count_len(int num){
	return ceil(log(num)/log(10));
}
int pow_(int times){
	int result=1;
	for(int i=0;i<times;i++){
		result*=10;
	}
	return result;
}
bool check(int num){
	int now = num;
	int len = count_len(num);
	for(int i=0;i<len;i++){
		//printf("%d\n",(now%10)*pow_(len-1));
		now = (int)((now%10)*pow_(len-1)) + (now/10);
		//printf("%d\n",now);
		if(binary_search(prime.begin(),prime.end(),now)== false){
			return false;
		}
	}
	return true;
}
int main(){
	int count = 0;
	build_prime();
	for(int i=0;i<prime.size();i++){
		if(check(prime[i])){
			count++;
			printf("%d,",prime[i]);
		}
	}	
	printf("\n%d\n",count);
}