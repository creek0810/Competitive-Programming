#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int a,b,goal;
int visit[1005][1005]={0};
vector<int>ans;
void dfs(int now_a,int now_b,vector<int>&table){
    //0 = fill a
    //1 = fill b 
    //2 = pour a b
    //3 = pour b a
    //4 = empty a
    //5 = empty b
    /*for(int i=0;i<table.size();i++){
        printf("%d ",table[i]);
    }
    printf("\n");*/
    if(now_b==goal){
        if(ans.size()==0 || ans.size()>table.size()){
            ans=table;
        }
        return;
    }
    vector<int>tmp;
    tmp=table;
    if(visit[a][now_b]==0){
        tmp.push_back(0);
        visit[a][now_b]=1;
        dfs(a,now_b,tmp);
        tmp.pop_back();
    }
    if(visit[now_a][b]==0){
        tmp.push_back(1);
        visit[now_a][b]=1;
        dfs(now_a,b,tmp);
        tmp.pop_back();
    }
    int new_a,new_b;
    if(now_a+now_b>b){
        new_a=now_a-(b-now_b);
        new_b=b;
    }else{
        new_b=now_a+now_b;
        new_a=0;
    }
    if(visit[new_a][new_b]==0){
        tmp.push_back(2);
        visit[new_a][new_b]=1;
        dfs(new_a,new_b,tmp);
        tmp.pop_back();
    }
    if(now_a+now_b>a){
        new_a=a;
        new_b=now_b-(a-now_a);
    }else{
        new_a=now_a+now_b;
        new_b=0;
    }
    if(visit[new_a][new_b]==0){
        tmp.push_back(3);
        visit[new_a][new_b]=1;
        dfs(new_a,new_b,tmp);
        tmp.pop_back();
    }
    if(visit[now_a][0]==0){
        tmp.push_back(5);
        visit[now_a][0]=1;
        dfs(now_a,0,tmp);
        tmp.pop_back();
    }
    if(visit[0][now_b]==0){
        tmp.push_back(4);
        visit[0][now_b]=1;
        dfs(0,now_b,tmp);
        tmp.pop_back();
    }
}
int main(){
    while(scanf("%d",&a)!=EOF){
        memset(visit,0,sizeof(int)*1005*1005);
        ans.clear();
        vector<int>table;
        scanf("%d%d",&b,&goal);
        dfs(0,0,table);
        for(int i=0;i<ans.size();i++){
            if(ans[i]==0){
                printf("fill A\n");
            }else if(ans[i]==1){
                printf("fill B\n");
            }else if(ans[i]==2){
                printf("pour A B\n");
            }else if(ans[i]==3){
                printf("pour B A\n");
            }else if(ans[i]==4){
                printf("empty A\n");
            }else{
                printf("empty B\n");
            }
        }
        printf("success\n");
    }
}