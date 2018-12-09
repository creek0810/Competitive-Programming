#include <cstdio>
#include <stack>
#include <sstream>
#include <vector>
#include <cstring> 
int cases;
using namespace std;
int solve(vector<int>&tar){
    stack<int>tmp;
    int i,k;
    for(i=1,k=0;i<=cases && k<tar.size();){
        if(tar[k]==i){
            k++;
            i++;
        }else if(!tmp.empty() && tmp.top()==tar[k]){
            tmp.pop();
            k++;
        }else{
            tmp.push(i);
            i++;
        }
    }
    while(!tmp.empty() && tmp.top()==tar[k]){
        k++;
        tmp.pop();
    }
    if(k==tar.size()){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    while(scanf(" %d",&cases)!=EOF){
        if(cases==0){
            break;
        }
        char str[5000]={0};
        while(1){
            vector<int>tar;
            for(int i=0;i<cases;i++){
                int tmp;
                scanf("%d",&tmp);
                tar.push_back(tmp);
                if(i==0 && tmp==0){
                    goto end;
                }
            }
            if(solve(tar)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
        end:
        printf("\n");
    }
}