// Orphan Process
// #include<stdio.h>
// #include<unistd.h>
// int main()
// {
//     int x=fork();
//     if(x!=0)
//         printf("Process id of Parent: %d\n",getpid());
//     else{
//         sleep(5);
//         printf("Process id of child: %d\n",getpid());
//         printf("It's Parent id: %d\n",getppid());
//     }
//     return 0;
// }

// Zombie Process
// #include<stdio.h>
// #include<unistd.h>
// int main()
// {
//     int x=fork();
//     if(x==0)
//         printf("Process id of Child: %d\n",getpid());
//         printf("It's Parent id: %d\n",getppid());
//     else{
//         sleep(5);
//         printf("Process id of Parent: %d\n",getpid());
//     }
//     return 0;
// }