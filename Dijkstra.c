#include <stdio.h>

int main(){
	int n,a[10][10],d[10],v[10]={0};
	int i,j,s,u,min;
	
	printf("Enter no. of vertices: ");
	scanf("%d",&n);
	
	printf("Enter cost matrix: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("Enter source vertex: ");
	scanf("%d",&s);
	
	for(i=0;i<n;i++){
		d[i]=(i==s)?0:9999;
	}
	
	for(i=0;i<n;i++){
		min=9999;
		u=-1;
		for(j=0;j<n;j++){
			if(!v[j] && d[j] < min){
				min=d[j];
				u=j;
			}
		}
		if(u==-1){
			break;
		}
		v[u]=1;
		for(j=0;j<n;j++){
			if(a[u][j] > 0 && !v[j] && d[u]+a[u][j] < d[j]){
				d[j]=d[u]+a[u][j];
			}
		}
	}
	printf("Shortest distances from %d\n",s);
	for(i=0;i<n;i++){
		if(d[i]==9999){
			printf("To %d: Unreachable\n",i);
		}
		else{
			printf("To %d: %d\n",i,d[i]);
		}
	}
	return 0;
}