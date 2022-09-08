// What is fork function? Write its process.
// Write a program to use fork function to create process.


#include<unistd.h>
#include<stdio.h>
int main()
{
	fork();
	printf("Program id: %d\n",getpid());
}
