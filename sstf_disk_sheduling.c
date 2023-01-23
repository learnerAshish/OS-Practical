#include<stdio.h>
#include<stdlib.h>
int main()
{
 int n,head;
 printf("Ashish Joshi B 20011905\n");
 printf("enter no. of elements: ");
 scanf("%d",&n);
 int arr[n];
 printf("enter array elements: ");
 for(int i=0;i<n;i++)
 scanf("%d",&arr[i]);
 printf("enter initial head position: ");
 scanf("%d",&head);
 int count=0,headmovement=0;
 printf("\n*******Seek Sequence*******\n");
 while(count!=n)
 {
 int min=1000,difference,index;
 for(int i=0;i<n;i++)
 {
 difference=abs(arr[i]-head);
 if(min>difference)
 {
 min=difference;
 index=i;
 }
 }
 headmovement+=min;
 head=arr[index];
printf("%d ",arr[index]);
 arr[index]=1000;
 count++;
 }
 printf("\ntotal head movement: %d\n",headmovement);
 return 0;
}

