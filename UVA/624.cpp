#include <cstdio>
#include <vector>
using namespace std;
vector<int>tmp;
vector<int>ans;
int maxsum;
int cases;
int limit_time;
void dp(int sum,int now,vector<int>&table){
    if(sum>maxsum){
        maxsum=sum;
        ans=tmp;
    }
    if(now==cases){
        return;
    }
    if(sum+table[now]<=limit_time){
        tmp.push_back(table[now]);
        sum+=table[now];
        dp(sum,now+1,table);
        tmp.pop_back();
        sum-=table[now];
    }
    dp(sum,now+1,table);
}
int main(){
    while(scanf("%d",&limit_time)!=EOF){
        maxsum=0;
        tmp.clear();
        vector<int>table;
        scanf("%d",&cases);
        for(int i=0;i<cases;i++){
            int tmp;
            scanf("%d",&tmp);
            table.push_back(tmp);
        }
        dp(0,0,table);
        int sum=0;
        for(int i=0;i<ans.size();i++){
            sum+=ans[i];
            if(i){
                printf(" ");
            }
            printf("%d",ans[i]);
        }
        printf(" sum:%d\n",sum);
    }
    return 0;
}