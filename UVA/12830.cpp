#include <cstdio>
#include <vector>
#define limit 10005
using namespace std;
typedef struct {
    int x,y;
}point;
int main(){
    int cases;
    scanf("%d",&cases);
    for(int times=1;times<=cases;times++){
        long long int ans=0;
        int table[limit][2]={0};
        vector<point>map;
        int x,y,ts;
        scanf("%d %d",&x,&y);
        scanf("%d",&ts);
        int tmpx,tmpy;
        for(int i=0;i<ts;i++){
            scanf("%d%d",&tmpx,&tmpy);
            map.push_back((point){tmpx,tmpy});
        }
        for(int i=1;i<=x;i++){
            for(int k=1;k<=y;k++){
                bool flag=false;
                for(int j=0;j<map.size();j++){
                    if(map[j].x+1==i && map[j].y+1==k){
                        talbe[k][i%2]=0;
                    }else{
                        talbe[k][i%2]=table[k][(i+1)%2]+1;
                    }
                }
            }
        }





        printf("Case %d: %lld\n",times,ans);
    }
}