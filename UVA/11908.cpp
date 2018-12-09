#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct inf{
    int start,end,cost;
};
bool cmp(inf a,inf b){
    return a.end<b.end;
}
int main(){
    int cases;
    scanf("%d",&cases);
    for(int k=0;k<cases;k++){
        int n;
        scanf("%d",&n);
        int dp[30005]={0};
        vector<inf>tmp;
        tmp.resize(n+1);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&tmp[i].start,&tmp[i].end,&tmp[i].cost);
            tmp[i].end+=(tmp[i].start-1);
        }
        sort(tmp.begin(),tmp.end(),cmp);    
        int ans=0;
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int loc=i-1;
            while(loc>0){
                if(tmp[i].end<tmp[loc].start || tmp[i].start>tmp[loc].end){
                    break;
                }
                loc--;  
            }
            dp[i]=max(dp[i-1],dp[loc]+tmp[i].cost);
        }

        printf("Case %d: %d\n",k+1,dp[n]);
    }
}