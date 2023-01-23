#include<unistd.h>
#include<stdio.h>
int main()
{
    fork();
    printf("Program Id: %d\n",getpid());
}