// WAP to implement zombie process.

#include <unistd.h>
#include<stdio.h>
int main()
{
    int x = fork();

    if (x==0){
    	printf("Process id of Child: %d\n",getpid());
    	printf("Its parent id: %d\n",getppid());
    }
    else{        
        sleep(5);
        printf("Process id of parent: %d\n",getpid());
    }
    return 0;
}
