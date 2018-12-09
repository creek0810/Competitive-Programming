#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;
struct pos{
    int pos,step;
};
int main(){
    int cases;
    int query=1;
    while(scanf("%d",&cases)!=EOF){
        map<int,vector<int> >table;      
        if(cases==0){
            break;
        } 
        for(int i=0;i<cases;i++){
            int start,end;
            scanf("%d %d",&start,&end);
            table[start].push_back(end);
            table[end].push_back(start);            
        }
        int start,ttl;
        while(scanf("%d%d",&start,&ttl)){
            map<int,int>visit; 
            if(start==0 && ttl==0){
                break;
            }
            queue<pos>qu;
            qu.push((pos){start,0});
            visit[start]++;
            map<int,int>::iterator it;
            while(!qu.empty() && qu.front().step<ttl){
                int now=qu.front().pos,step=qu.front().step;
                qu.pop();
                for(int k=0;k<table[now].size();k++){
                    it=visit.find(table[now][k]);
                    if(it==visit.end()){
                        qu.push((pos){table[now][k],step+1});
                        visit[table[now][k]]++;
                    }
                    
                }
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",query++,(int)table.size()-(int)visit.size() ,start,ttl);
        }
    }
}