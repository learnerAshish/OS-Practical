// #include <stdio.h>
// #include <stdbool.h>
// struct process_info
// {
//  int max[10];
//  int allocated[10];
//  int need[10];
// };
// int no_of_process,no_of_resources;
// void input(struct process_info process[no_of_process],int available[no_of_resources])
// {
//  for(int i=0;i<no_of_process;i++)
//  {
//  printf("Enter process[%d] info\n",i);
//  printf("Enter Maximum Need: ");
//  for(int j=0;j<no_of_resources;j++)
//  scanf("%d",&process[i].max[j]);
//  printf("Enter No. of Allocated Resources for this process: ");
//  for(int j=0;j<no_of_resources;j++)
//  {
//  scanf("%d",&process[i].allocated[j]); 
//  process[i].need[j]= process[i].max[j] - process[i].allocated[j];
//  }
//  }
//  printf("Enter Available Resources: ");
//  for(int i=0;i<no_of_resources;i++)
//  {
//  scanf("%d",&available[i]);
//  }
// }
// void showTheInfo(struct process_info process[no_of_process])
// {
//  printf("\nPID\tMaximum\t\tAllocated\tNeed\n");
//  for(int i=0;i<no_of_process;i++)
//  {
//  printf("P[%d]\t",i);
//  for(int j=0;j<no_of_resources;j++)
//  printf("%d ",process[i].max[j]);
//  printf("\t\t");
//  for(int j=0;j<no_of_resources;j++)
//  printf("%d ",process[i].allocated[j]); 
//  printf("\t\t");
//  for(int j=0;j<no_of_resources;j++)
//  printf("%d ",process[i].need[j]);
//  printf("\n");
//  }
// }
// bool applySafetyAlgo(struct process_info process[no_of_process],int available[no_of_resources],int safeSequence[no_of_process])
// {
//  bool finish[no_of_process];
//  int work[no_of_resources]; 
//  for(int i=0;i<no_of_resources;i++)
//  {
//  work[i]=available[i]; 
//  }
//  for(int i=0;i<no_of_process;i++)
//  finish[i]=false; 
//  bool proceed=true;
//  int k=0;
//  while(proceed)
//  {
//  proceed=false;
//  for(int i=0;i<no_of_process;i++)
//  { 
//  bool flag=true;
//  if(finish[i]==false)
//  {
// for(int j=0;j<no_of_resources;j++)
//  {
//  if(process[i].need[j] <= work[j])
//  {
//  continue;
//  }
//  else
//  {
//  flag=false;
//  break;
//  }
//  }
//  if(flag==false)
//  continue;
//  for(int j=0;j<no_of_resources;j++) 
//  work[j]=work[j]+ process[i].allocated[j];
//  finish[i]=true;
//  safeSequence[k++]=i;
//  proceed=true; 
 
//  }
//  }
//  }
//  int i;
//  for( i=0;i<no_of_process&&finish[i]==true;i++)
//  {
//  continue;
//  }
//  if(i==no_of_process)
//  return true;
//  else
//  return false;
// }
// bool isSafeState(struct process_info process[no_of_process],int available[no_of_resources],int safeSequence[no_of_process])
// {
// if(applySafetyAlgo(process,available,safeSequence)==true)
//  return true;
//  return false;
 
// }
// int main()
// {
//  printf("AshishJoshi B 20011905\n");
//  printf("Enter No of Process: ");
//  scanf("%d",&no_of_process);
//  printf("Enter No of Resource Instances in system: ");
//  scanf("%d",&no_of_resources);
//  int available[no_of_resources];
//  int safeSequence[no_of_process];
//  struct process_info process[no_of_process];
 
//  printf(" Enter details of processes\n");
//  input(process,available);
//  showTheInfo(process);
//  if(isSafeState(process,available,safeSequence))
//  {
//  printf("\nSystem is in SAFE State\n");
//  printf("Safe Sequence is: ");
//  for(int i=0;i<no_of_process;i++)
//  printf("P[%d] ",safeSequence[i]);
//  printf("1");
//  }
//  else
//  printf("0");
//  return 0;
// }


#include<stdio.h>
int main()
{
    int n,r;
    printf("enter number of process:");
    scanf("%d",&n);
    printf("enter number of resources:");
    scanf("%d",&r);
    int total[r];
    int used[r];
    for(int i=0;i<r;i++)
    {
        printf("enter total number of resource of resource %d:",i+1);
        scanf("%d",&total[i]);
        used[i]=0;
    }
    int allo[n][r];
    printf("enter allocated matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<r;j++)
        {
            scanf("%d",&allo[i][j]);
            used[j]+=allo[i][j];
        }
    }
    int max[n][r];
    printf("enter max need matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<r;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    int remain[n][r];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<r;j++)
        {
            remain[i][j]=max[i][j]-allo[i][j];
        }
    }
    int avail[r];
    for(int i=0;i<r;i++)
    {
        avail[i]=total[i]-used[i];
    }
    int comp[n],a=1;
    for(int i=0;i<n;i++)
    {
        comp[i]=-1;
    }
    int flag=0,q=0;
    while(a)
    {
        for(int i=0;i<n;i++)
        {
            if(remain[i][0]<=avail[0]&&max[i][0]!=-1)
            {
                flag=0;
                for(int j=1;j<r;j++)
                {
                    if(remain[i][j]>avail[j])
                        flag=1;
                }
                if(flag==0)
                {
                    for(int j=0;j<r;j++)
                    {
                        avail[j]+=allo[i][j];
                        max[i][j]=-1;
                    }
                    comp[q++]=i+1;
                }
            }
            if(comp[n-1]!=-1)
            {
                a=0;
                break;
            }
        }
    }
    // if(a==1)
    // {
    //     printf("Deadlock detected........");
    //     return 0;
    // }
    for(int i=0;i<n;i++)
    {
        printf("P%d--->",comp[i]);
    }
    return 0;
}