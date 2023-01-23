#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int headmovement=0;
	int choice;
	printf("For left 1 for right 0 : ");
	scanf("%d",&choice);
  int l=0,r=199;
	int head;
	printf("enter head");
	scanf("%d",&head);
  for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				int temp= a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	int x;
	for(int i=0;i<n;i++){
		if(a[i]>head){
			x=i;
			break;
		}
		
	}

if(choice ==0){
	printf("Sequence is :  ");
	for(int i=x;i<n;i++){
       printf("%d ",a[i]);
	}
    printf("%d ",r);
	headmovement+= r-head;
	for(int i=x-1;i>=0;i--){
       printf("%d ",a[i]);
	}
	headmovement+= r-a[0];
	printf("\n total head movement : %d",headmovement);}

	else{
		printf("Sequence is :  ");
	for(int i=x;i>=0;i--){
       printf("%d ",a[i]);
	}
    printf("0 ");
	headmovement+=head;
	for(int i=x+1;i<n;i++){
       printf("%d ",a[i]);
	}
	headmovement+= a[n-1];
	printf("\n total head movement : %d",headmovement);
	}
}