#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef struct{
    char start,end;
}word;
int ts;
int solve(vector<word>&table){
    //0=can 1=can't
    int V[100005][2]={0};
    // 0=out 1=in
    for(int i=0;i<ts;i++){
        for(int k=i+1;k<ts;k++){
            printf("%c%c %c%c\n",table[i].start,table[i].end,table[k].start,table[k].end);
            if(table[i].start==table[k].end){
                printf("start-end");
                V[k][1]++;
                V[i][0]++;
            }
            if(table[k].start==table[i].end){
                printf("end-start\n");
                V[i][1]++;
                V[k][0]++;
            }
        }
    }
    bool out=false,in=false;
    for(int i=0;i<ts;i++){
        printf("%d %d\n",V[i][0],V[i][1]);
    }
    for(int i=0;i<ts;i++){
        if(V[i][0]-V[i][1]==1){
            if(out==false){
                out=true;
            }else{
                return 1;
            }
        }else if(V[i][1]-V[i][0]==1){
            if(in==false){
                in=true;
            }else{
                return 1;
            }
        }else if(V[i][1]!=V[i][0] || (V[i][0]==0 && V[i][1]==0)){
            return 1;
        }

    }
    if(out==false && in==false){
        return 0;
    }else if(out==true && in==true){
        return 0;
    }
    return 1;
}
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        scanf(" %d",&ts);
        getchar();
        vector<word>table;
        vector<word>::iterator it;
        int V[100005][2]={0};
        for(int i=0;i<ts;i++){
            char tmp[1005]={0};   
            gets(tmp);
            table.push_back((word){tmp[0],tmp[strlen(tmp)-1]});
        }
        if(solve(table)){
            printf("The door cannot be opened.\n");
        }else{
            printf("Ordering is possible.\n");
        }
    }    
    return 0;
}