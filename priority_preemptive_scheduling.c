#include<stdio.h>
#include<stdlib.h>
struct priority{
  int at,bt,ct,rbt,tat,wt,p,rt,st;
};
int com(const void * p, const void *q){
  int l= ((struct priority *)p)->at;
  int r= ((struct priority *)q)->at;
  return (l-r);
}
int main(){
  int n;
  scanf("%d",&n);
  int avgtat=0,avgrt=0,avgwt=0;
  struct priority  a[n];
  for(int i=0;i<n;i++){
    scanf("%d %d %d",&a[i].at,&a[i].bt,&a[i].p);
    a[i].rbt=a[i].bt;
  }
  qsort((void *)a , n , sizeof(a[0]),com);
  int pc =0;
  int cpuidle =0;
  int completed=0;
  int prev =0;
  while(completed!=n){
    int k=-1;
    int prio= 999999;
    for(int i=0;i<n;i++){
      if(a[i].at<=pc && a[i].rbt!=0){
        if(a[i].p<prio){
          k=i;
          prio=a[i].p;
        }
        else if(a[i].p==prio){
          if(a[i].at<a[k].at){
            k=i;
            prio=a[i].p;
          }
        }
      }
    }
  if(k!=-1){
    if(a[k].bt==a[k].rbt){
      a[k].st=pc;
      cpuidle += pc - prev;
    }
    a[k].rbt--;
    pc++;
    prev=pc;
    if(a[k].rbt==0){
      completed++;
    a[k].ct=pc;
    a[k].tat=a[k].ct-a[k].at;
    a[k].wt=a[k].tat-a[k].bt;
    a[k].rt=a[k].st-a[k].at;
    avgtat+=a[k].tat;
    avgwt+=a[k].wt;
    avgrt+=a[k].rt;
    }
  }
  else{
    pc++;
  }
  }
  printf("at\tbt\tst\ttat\tct\twt\trt\n");
  for(int i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",a[i].at,a[i].bt,a[i].st,a[i].tat,a[i].ct,a[i].wt,a[i].rt);
  }
  printf("average tat = %f \n ",avgtat*1.0/n*1.0);
  printf("average wt = %f \n ",avgwt*1.0/n*1.0);
  printf("average rt = %f \n ",avgrt*1.0/n*1.0);
  printf("Cpu idle time = %f \n ",cpuidle);
  printf("Cycle time = %d \n",pc-a[0].at);
  printf("cpu utilisation := %f \n",((pc-a[0].at - cpuidle )/(pc-a[0].at)*1.0)*100);
}