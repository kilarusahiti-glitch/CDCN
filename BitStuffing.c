#include <stdio.h>

int main(){
	char data[200];
	int i,ones=0;
	
	printf("Enter data: ");
	scanf("%199s",data);
	
	printf("Stuffed Bits: ");
	
	for(i=0;data[i]!='\0';i++){
		printf("%c",data[i]);
		if(data[i]=='1'){
			ones++;
			if(ones==5){
				printf("0");
				ones=0;
			}
	    }
		else{
			ones=0;
    	}
	}
	printf("\n");
	return 0;
}