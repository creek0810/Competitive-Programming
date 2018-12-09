#include <cstdio>
using namespace std;
void doubleF(int *num){
    *num *= 2;
}
int main(){
    int num=2;
    doubleF(&num);
    printf("%d\n",num);
}