#include <stdio.h>
#include <string.h>
int main(){
	char table[]={"`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"};
	char input [5000]={0};
	char ch;
	while((ch=getchar())!=EOF){
		// for(int i=0;i<strlen(input);i++){
		// printf("%c ",ch);
		if(ch==' '){
			printf(" ");
		}else if(ch=='\n'){
			printf("\n");
		}else{
			// printf("start");
			for(int z=0;z<strlen(table);z++){
				 printf("%c",table[z]);
				if(ch==table[z]){
					printf("%c",table[z-2]);
				}
			}
			// printf("\n");
		}
	}
}		