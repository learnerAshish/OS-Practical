// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
// int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;
// printf("\nAshish Joshi B 20011905\n");
// printf("Enter the number of Request: ");
// scanf("%d", &n);
// printf("Enter the Requests sequence: ");
// for (i = 0; i < n; i++)
//  scanf("%d", &RQ[i]);
// printf("Enter initial head position: ");
// scanf("%d", &initial);
// printf("Enter total disk size: ");
// scanf("%d", &size);
// printf("Enter the head movement direction for high 1 and for low 0: ");
// scanf("%d", &move);
// for (i = 0; i < n; i++)
// {
//  for (j = 0; j < n - i - 1; j++){
//  if (RQ[j] > RQ[j + 1]){
//  int temp;
//  temp = RQ[j];
//  RQ[j] = RQ[j + 1];
//  RQ[j + 1] = temp;
//  }
//  }
// }
// int index;
// for (i = 0; i < n; i++){
//  if (initial < RQ[i]){
//  index = i;
//  break;
//  }
// }
// if (move == 1){
//  for (i = index; i < n; i++){
//  TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
//  initial = RQ[i];
//  }
//  TotalHeadMoment = TotalHeadMoment + abs(size - RQ[i - 1] - 1);
//  TotalHeadMoment = TotalHeadMoment + abs(size - 1 - 0);
//  initial = 0;
//  for (i = 0; i < index; i++){
//  TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
//  initial = RQ[i];
//  }
// }
// else{
//  for (i = index - 1; i >= 0; i--){
//  TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
//  initial = RQ[i];
//  }
//  TotalHeadMoment = TotalHeadMoment + abs(RQ[i + 1] - 0);
//  TotalHeadMoment = TotalHeadMoment + abs(size - 1 - 0);
//  initial = size - 1;
//  for (i = n - 1; i >= index; i--){
//  TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
//  initial = RQ[i];
//  }
// }
// printf("Total head movement is %d", TotalHeadMoment);
// return 0;
// }

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
		for(int j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				int temp= a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	int x;
	for(int i=0;i<n;i++){
		if(a[i]>=head){
			x=i;
			break;
		}	
	}
if(choice ==0){
	printf("Sequence is :  ");
	for(int i=x;i<n;i++){
       printf("%d ",a[i]);
	}
	headmovement+=r-head;
    headmovement+=r;
	for(int i=0;i<x;i++){
       printf("%d ",a[i]);
	}
	headmovement+= a[x-1];
	printf("\n total head movement : %d",headmovement);}

	else{
		printf("Sequence is :  ");
	for(int i=x;i>=0;i--){
       printf("%d ",a[i]);
	}
	headmovement+=head;
    headmovement+=r;
	for(int i=n;i>x;i--){
       printf("%d ",a[i]);
	}
	headmovement+= r-a[x];
	printf("\n total head movement : %d",headmovement);
	}
}