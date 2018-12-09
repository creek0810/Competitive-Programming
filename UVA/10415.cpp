#include <cstdio>
#include <cstring>
using namespace std;
void to_press(int start,int end,int table[],int now_state[]){
    for(int k=start;k<=end;k++){
        if(now_state[k]==0){
            now_state[k]=1;
            table[k]++;
        }
    }
}
void not_to_press(int start,int end,int table[],int now_state[]){
    for(int k=start;k<=end;k++){
        if(now_state[k]==1){
            now_state[k]=0;
        }
    }
}
void solve(int table[],int now_state[],char str[]){
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='c'){
            not_to_press(1,1,table,now_state);
            to_press(2,4,table,now_state);
            not_to_press(5,6,table,now_state);
            to_press(7,10,table,now_state);
        }else if(str[i]=='d'){
            not_to_press(1,1,table,now_state);
            to_press(2,4,table,now_state);
            not_to_press(5,6,table,now_state);
            to_press(7,9,table,now_state);
            not_to_press(10,10,table,now_state);
        }else if(str[i]=='e'){
            not_to_press(1,1,table,now_state);
            to_press(2,4,table,now_state);
            not_to_press(5,6,table,now_state);
            to_press(7,8,table,now_state);
            not_to_press(9,10,table,now_state);
        }else if(str[i]=='f'){
            not_to_press(1,1,table,now_state);
            to_press(2,4,table,now_state);
            not_to_press(5,6,table,now_state);
            to_press(7,7,table,now_state);
            not_to_press(8,10,table,now_state);
        }else if(str[i]=='g'){
            not_to_press(1,1,table,now_state);
            to_press(2,4,table,now_state);
            not_to_press(5,10,table,now_state);
        }else if(str[i]=='a'){
            not_to_press(1,1,table,now_state);
            to_press(2,3,table,now_state);
            not_to_press(4,10,table,now_state);
        }else if(str[i]=='b'){
            not_to_press(1,1,table,now_state);
            to_press(2,2,table,now_state);
            not_to_press(3,10,table,now_state);
        }else if(str[i]=='C'){
            not_to_press(1,2,table,now_state);
            to_press(3,3,table,now_state);
            not_to_press(4,10,table,now_state);
        }else if(str[i]=='D'){
            to_press(1,4,table,now_state);
            not_to_press(5,6,table,now_state);
            to_press(7,9,table,now_state);
            not_to_press(10,10,table,now_state);
        }else if(str[i]=='E'){
            to_press(1,4,table,now_state);
            not_to_press(5,6,table,now_state);
            to_press(7,8,table,now_state);
            not_to_press(9,10,table,now_state);
        }else if(str[i]=='F'){
            to_press(1,4,table,now_state);
            not_to_press(5,6,table,now_state);
            to_press(7,7,table,now_state);
            not_to_press(8,10,table,now_state);
        }else if(str[i]=='G'){
            to_press(1,4,table,now_state);
            not_to_press(5,10,table,now_state);
        }else if(str[i]=='A'){
            to_press(1,3,table,now_state);
            not_to_press(4,10,table,now_state);
        }else if(str[i]=='B'){
            to_press(1,2,table,now_state);
            not_to_press(3,10,table,now_state);
        }
    }
}
int main(){
    int cases;
    scanf("%d",&cases);
    getchar();
    while(cases--){
        int table[11]={0};
        int now_state[11]={0};
        char str[205]={0};
        gets(str);
        solve(table,now_state,str);
        for(int i=1;i<=10;i++){
            if(i!=1){
                printf(" ");
            }
            printf("%d",table[i]);
        }
        printf("\n");
    }
}