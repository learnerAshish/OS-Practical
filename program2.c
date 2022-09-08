/*
WAP to create a child process in parallel to main process. Define an array of numbers. The child process has to calculate the sum of even numbers and parent process has to calculate sum of odd numbers.
*/
#include<stdio.h>
#include<unistd.h>
int main()
{
	int odd_sum=0,even_sum=0;
	int a[5]={1,2,3,4,5};
	int x=fork();
	if(x!=0)
	{
		for(int i=0;i<5;i++)
		{
			if(a[i]%2==0)
				even_sum += a[i];	
		}
		printf("Even sum = %d and Process id = %d\n",even_sum,getpid());
	}
	else
	{
		for(int i=0;i<5;i++)
		{
			if(a[i]%2!=0)
				odd_sum += a[i];	
		}
		printf("Odd sum = %d and Process id = %d\n",odd_sum,getpid());
	}
}
	

