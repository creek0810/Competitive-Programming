#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int color[205];
vector<int>table[205];
bool flag;
void dfs(int now){
    if(flag==false){
        return;
    }
    int newcolor;
    newcolor=(color[now]==1) ? 2 : 1 ;
    for(int i=0;i<table[now].size();i++){
        if(color[table[now][i]]!=0){
            if(color[table[now][i]]!=newcolor){
                flag=false;
                break;
            }
        }else{
            color[table[now][i]]=newcolor;
            dfs(table[now][i]);
        }

    }
}
void init(){
    for(int i=0;i<205;i++){
        table[i].clear();
    }
    memset(color,0,sizeof(color));
    flag=true;
}
int main(){
    int nodes ,edge;
    while(scanf("%d",&nodes)!=EOF){
        if(nodes==0){
            break;
        }
        init();
        scanf("%d",&edge);
        for(int i=0;i<edge;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            if(a>b){
                table[b].push_back(a);
            }else{
                table[a].push_back(b);
            }
        }
        color[0]=1;
        dfs(0);
        if(flag==true){
            printf("BICOLORABLE.\n");
        }else{
            printf("NOT BICOLORABLE.\n");
        }
    }
}