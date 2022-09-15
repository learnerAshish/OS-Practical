// WAP to implement orphan process.

#include <unistd.h>
#include<stdio.h>
int main()
{
    int x = fork();

    if (x!=0){
    	printf("Process id of Parent: %d\n",getpid());
    }
    else{        
        sleep(5);
        printf("Process id of child: %d\n",getpid());
        printf("Its parent id: %d\n",getppid());
    }
    return 0;
}
