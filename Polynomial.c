#include <stdio.h>
#include <string.h>

void divide(char a[],char b[]){
	int i,j,n=strlen(a),m=strlen(b);
	for(i=0;i<=n-m;i++){
		if(a[i]=='1'){
			for(j=0;j<m;j++){
				a[i+j]=(a[i+j]==b[j])?'0':'1';
			}
		}
	}
}

int main(){
	char data[100],gen[30];
	char temp[150], code[150], recv[150];
	int i,n,m,error=0;
	
	printf("Enter dataword: ");
	scanf("%99s",data);
	
	printf("Enter generator bits: ");
	scanf("%29s",gen);
	
	n=strlen(data);
	m=strlen(gen);
	
	strcpy(temp,data);
	for(i=0;i<m-1;i++){
		temp[n+i]='0';
	}
	temp[n+m-1]='\0';
	divide(temp,gen);
	
	strcpy(code,data);
	for(i=0;i<m-1;i++){
		code[n+i]=temp[n+i];
	}
	code[n+m-1]='\0';
	
	printf("CRC: %s\n",code+n);
	printf("Codeword: %s\n",code);
	
	printf("Enter received codeword: ");
	scanf("%149s",recv);
	
	divide(recv,gen);
	for(i=(int)strlen(recv)-m+1;i<(int)strlen(recv);i++){
		if(recv[i]=='1'){
			error=1;
		}
	}
	
	if(error){
		printf("Error detected");
	}
	else{
		printf("No error detected");
	}
	return 0;
}