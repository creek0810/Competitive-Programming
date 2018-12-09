#include <cstdio>
using namespace std;
int main(){
    long long int start,end;
    while(scanf("%lld",&start)!=EOF){
        scanf("%lld",&end);
        long long int now=start;
        while(now<end){
            start++;
            now+=start;
        }
        printf("%lld\n",start);
    }
}