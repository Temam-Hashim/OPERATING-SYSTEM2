#include<stdio.h>

int main()

{

 int at[10],bt[10],rt[10],endTime,i,smallest;
 int tat,wt;

 int remain=0,n,time,sum_wait=0,sum_turnaround=0;

 printf("Enter no of Processes : ");

 scanf("%d",&n);

 printf("Enter arrival time for each process:\n ");
 for(i=0;i<n;i++)
 {
 printf("P%d: ",i);
 scanf("%d",&at[i]);
}

printf("Enter burst time for each process \n: ");
 for(i=0;i<n;i++)
 {
  printf("P%d: ",i);
 scanf("%d",&bt[i]);

 rt[i]=bt[i];

 }

 printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");

 rt[9]=9999;

 for(time=0;remain!=n;time++)

 {

 smallest=9;

 for(i=0;i<n;i++)

 {

 if(at[i]<=time && rt[i]<rt[smallest] && rt[i]>0)

 {

 smallest=i;

 }

 }

 rt[smallest]--;

 if(rt[smallest]==0)

 {

 remain++;
 endTime=time+1;

 tat=endTime-at[smallest];
 wt=tat-bt[smallest];

 printf("\nP[%d]\t|\t%d\t|\t%d",smallest+1,tat,wt);

 sum_wait=sum_wait+at;

 sum_turnaround=sum_turnaround+tat;

 }

 }

 printf("\n\nAverage waiting time = %f\n",sum_wait*1.0/n);

 printf("\nAverage Turnaround time = %f\n",sum_turnaround*1.0/n);

 return 0;

}
