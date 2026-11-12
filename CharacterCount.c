#include <stdio.h> 
#include <string.h>

int main(){
	char data[100];
	
	printf("Enter data: ");
	scanf("%99s",data);
	
	printf("Frame: %d%s\n",(int)strlen(data),data);
	return 0;
}