#include <cstdio>
#define limit 100005
using namespace std;
int tree[limit<<2];
int N,K,tar_a,tar_b;
int build(int now,int left,int right){
    if(left==right){
        int num;
        scanf("%d",&num); 
        if(num>0){
            tree[now]=1;
        }else if(num==0){
            tree[now]=0;
        }else{
            tree[now]=-1;
        }
        return tree[now];
    }
    int mid=(left+right)>>1;
    return tree[now]=build(now*2,left,mid)*build(now*2+1,mid+1,right);
}
int update(int now,int left,int right){
    if(left==tar_a && right==tar_a){
        if(tar_b>0){
            tree[now]=1;
        }else if(tar_b==0){
            tree[now]=0;
        }else{
            tree[now]=-1;
        }
        return tree[now];
    }
    int mid=(left+right)>>1;
    if(tar_a>mid){
        tree[now]=tree[now*2]*update(now*2+1,mid+1,right);
    }else{
        tree[now]=tree[now*2+1]*update(now*2,left,mid);
    }
    return tree[now];
}
int querry(int now,int left,int right){
    if(tar_b<left || tar_a>right){
        return 1;
    }else if(tar_a<=left && tar_b>=right){
        return tree[now];
    }
    int mid=(left+right)>>1;
    if(tar_b<=mid){
        return querry(now*2,left,mid);
    }else if(tar_a>mid){
        return querry(now*2+1,mid+1,right);
    }
    return querry(now*2,left,mid)*querry(now*2+1,mid+1,right);
}
int main(){
    while(scanf("%d",&N)!=EOF){
        scanf("%d",&K);
        build(1,1,N);
        char ch;
        for(int i=0;i<K;i++){
            scanf(" %c%d%d",&ch,&tar_a,&tar_b);
            if(ch=='C'){
                update(1,1,N);
            }else{
                int now=querry(1,1,N);
                if(now>0){
                    printf("+");
                }else if(now==0){
                    printf("0");
                }else{
                    printf("-");
                }

            }
        }
        printf("\n");
    }
}