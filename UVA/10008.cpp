#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
	int cases;
	scanf("%d",&cases);
	int count[28]={0};
	char ans[28]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	getchar();
	while(cases--){
		char tmp[1500]={0};
		gets(tmp);
		for(int i=0;i<strlen(tmp);i++){
			tmp[i]=toupper(tmp[i]);
			if(tmp[i]<=90 && tmp[i]>=65){
				count[tmp[i]-'A']++;
			}
		}
	}	

	char tmpp;
	int tmppp;
	for(int i=0;i<=25;i++){
		for(int j=24;j>=i;j--){
			// printf("%c %d %c %d",count[i)
			if(count[j]<count[j+1]){
				tmpp =ans[j];
				ans[j]=ans[j+1];
				ans[j+1]=tmpp;
				tmppp=count[j];
				count[j]=count[j+1];
				count[j+1]=tmppp;				
			}else if(count[j]==count[j+1]){
				if(ans[j]>ans[j+1]){		
					tmpp =ans[j];
					ans[j]=ans[j+1];
					ans[j+1]=tmpp;
					tmppp=count[j];
					count[j]=count[j+1];
					count[j+1]=tmppp;
				}
			}
		}
	}
	for(int i=0;count[i]>0;i++){
		printf("%c %d\n",ans[i],count[i]);
	}

}