//ROUND ROBIN ALGORITHM

#include<stdio.h> 
int main() 
{ 
 
  int i,j,n,Ctime,remain,flag=0,time_quantum; 
  int wt=0,tat=0,Twt,Ttat,at[10],bt[10],rt[10]; 
  printf("Enter Total Number of Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(i=0;i<n;i++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Number %d\n",i); 
    scanf("%d",&at[i]); 
    scanf("%d",&bt[i]); 
    rt[i]=bt[i]; 
  } 

  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\tArrival_Time\t Burst_Time\t Completion_Time\t Turnaround_Time\t Waiting_Time\n\n"); 
  for(Ctime=0,i=0;remain!=0;) 
  { 
    if(rt[i]<=time_quantum && rt[i]>0) 
    { 
      Ctime=Ctime+rt[i]; 
      rt[i]=0; 
      flag=1; 
    } 
    else if(rt[i]>0) 
    { 
      rt[i]=rt[i]-time_quantum; 
      Ctime=Ctime+time_quantum; 
    } 
    if(rt[i]==0 && flag==1) 
    { 
      remain--; 
      tat=Ctime-at[i];
      wt=tat-bt[i];
      printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",i+1,at[i],bt[i],Ctime,tat,wt); 
      Twt=Twt+wt; 
      Ttat=Ttat+tat; 
      flag=0; 
    } 
  if(i==n-1) 
      i=0; 
    else if(at[i+1]<=Ctime) 
      i++; 
    else 
      i=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",Twt*1.0/n); 
  printf("Avg Turnaround Time = %f\n",Ttat*1.0/n); 
  
  return 0; 
}
