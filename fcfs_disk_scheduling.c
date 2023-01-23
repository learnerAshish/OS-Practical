#include<stdio.h>
#include<stdlib.h>
int main()
{
 int n,head;
 printf("Ashish Joshi B 20011905\n");
 printf("enter no. of elements: ");
 scanf("%d",&n);
 int arr[n];
 printf("\nenter array elements: ");
 for(int i=0;i<n;i++)
 scanf("%d",&arr[i]);
 printf("\nenter initial head position: ");
 scanf("%d",&head);
 int headmovement=0;
 for(int i=0;i<n;i++)
 {
 headmovement+=abs(arr[i]-head);
 head=arr[i];
 }
 printf("\nTotal Head Movement: %d\n",headmovement);
}
