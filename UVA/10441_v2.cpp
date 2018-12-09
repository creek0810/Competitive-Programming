#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int in_out_times[30][2];
int in_out_alp[30][2];
// 0=in 1=out
int group[30];
int used_letters,combine_times;
int used[30][1005];
vector<string>word[30];
int start_point;
vector<string>ans;
void init(){
    memset(in_out_times,0,sizeof(in_out_times));
    memset(in_out_alp,0,sizeof(in_out_alp));
    memset(group,0,sizeof(group));
    memset(used,0,sizeof(used));
    for(int i=0;i<30;i++){
        word[i].clear();
        group[i]=i;
    }
    ans.clear();
    start_point=-1;
    used_letters=0;
    combine_times=1;
}
void combine(int a,int b){
    if(group[a]==group[b]){
        return;
    }
    int old=group[a];
    for(int i=0;i<26;i++){
        if(group[i]==old){
            group[i]=group[b];
        }
    }
    combine_times++;
}
void input(){
    int ts;
    scanf(" %d",&ts);
    getchar();
    for(int i=0;i<ts;i++){
        string tmp;
        cin >> tmp;
        int start=tmp[0]-'a';
        int end=tmp[tmp.length()-1]-'a';
        word[tmp[0]-'a'].push_back(tmp);
        if(in_out_times[start][0]==0 && in_out_times[start][1]==0){

            used_letters++;
        }
        in_out_times[start][1]++;

        if(in_out_times[end][0]==0 && in_out_times[end][1]==0){
            used_letters++;
        }
        in_out_times[end][0]++;

        combine(start,end);
        in_out_alp[start][end]++;
    }
}
bool check(){
    int flag=0;
    if(used_letters!=combine_times){
        return false;
    }
    for(int i=0;i<26;i++){
        if(in_out_times[i][0]-1==in_out_times[i][1]){
            flag++;
        }else if(in_out_times[i][1]-1==in_out_times[i][0]){
            flag++;
            start_point=i;
        }else if(in_out_times[i][1]!=in_out_times[i][0]){
            return false;
        }
    }
    if(flag>2 || flag%2==1){
        return false;
    }
    return true;
}
void dfs(int now){
    for(int i=0;i<word[now].size();i++){
        if(used[now][i]==1){
            continue;
        }
        int end=word[now][i].length()-1;
        used[now][i]=1;
        dfs(word[now][i][end]-'a');
        ans.push_back(word[now][i]);
    }
}
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        init();
        input();
        if(!check()){
            cout << "***";
        }else{
            for(int i=0;i<26;i++){
                sort(word[i].begin(),word[i].end());
            }
            if(start_point!=-1){
                dfs(start_point);
            }else{
                for(int i=0;i<30;i++){
                    if(word[i].size()!=0){
                        dfs(i);
                        break;
                    }
                }
            }
            for(int i=ans.size()-1;i>=0;i--){
                if(i!=ans.size()-1){
                    cout << ".";
                }
                cout << ans[i];
            }
        }
        cout << "\n";
    }
}