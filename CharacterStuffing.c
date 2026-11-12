#include <stdio.h>

int main(){
	char data[100];
	int i;
	
	printf("Enter data: ");
	scanf("%99s",data);
	
	printf("Frame: F");
	for(i=0;data[i]!='\0';i++){
		if(data[i]=='F'||data[i]=='E'){
			printf("E");
		}
		printf("%c",data[i]);
	}
	printf("F");
	return 0;
}