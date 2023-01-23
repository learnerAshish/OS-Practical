// #include<stdio.h>
// #include<unistd.h>
// int main()
// {
//     int odd_sum=0,even_sum=0;
//     int a[5]={6,7,8,9,10};
//     int x=fork();
//     if(x!=0)
//     {
//         for(int i=0;i<5;i++)
//         {
//             if(a[i]%2==0)
//                 even_sum+=a[i];
//         }
//         printf("Even sum: %d and Process id: %d\n",even_sum,getpid());
//     }
//     else
//     {
//         for(int i=0;i<5;i++)
//         {
//             if(a[i]%2!=0)
//                 odd_sum+=a[i];
//         }
//         printf("Odd sum: %d and Process id: %d\n",odd_sum,getpid());
//     }
// }