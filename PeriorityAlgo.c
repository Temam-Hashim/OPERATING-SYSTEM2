#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  char p[10][5],temp[5];
  int i,j,bt[10],wt[10],totwt=0,tottat=0,pr[10],temp1,n,ct[10],tat[10],at[10];
  float avgwt,avgtat;
 
  printf("enter no of processes: ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  printf("enter process%d name:",i+1);
  scanf("%s",p[i]);
  printf("enter Arrival time of p%d: ",i+1);
  scanf("%d",&at[i]);
  printf("enter burst time of p%d: ",i+1);
  scanf("%d",&bt[i]);
  printf("enter priority of p%d: ",i+1);
  scanf("%d",&pr[i]);
  }
  for(i=0;i<n-1;i++)
  {
 for(j=i+1;j<n;j++)
  {
   if(pr[i]>pr[j])
   {
//swap the prority time
   temp1=pr[i];
   pr[i]=pr[j];
   pr[j]=temp1;
//swap the burst time as well
   temp1=bt[i];
   bt[i]=bt[j];
   bt[j]=temp1;
//swap the proccess as wll
   strcpy(temp,p[i]);
   strcpy(p[i],p[j]);
   strcpy(p[j],temp);
//swap the arrival time
   temp1=at[i];
   at[i]=at[j];
   at[j]=temp1;
   }
  }
  }
wt[0]=0;

for(i=0;i<=n;i++){
wt[i]=0;
ct[i]=0;
for(j=0;j<=i;j++)
 ct[i]=ct[i]+bt[j];
 tat[i]=ct[i]-at[i];
 wt[i]=tat[i]-bt[i];
}
    printf("\n\nProcess\t|Arrival_time\t|Burst_Time\t|completion_time\t|Turnaround_Time\t|Waiting_Time\n\n");
 
    //calculating turnaround time
    for(i=0;i<n;i++)
      {
         
         totwt=(totwt+wt[i]);
        tottat=(tottat+tat[i]);

        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
 
    avgwt=(float)totwt/i;
   avgtat=(float)tottat/i;
    printf("\n\nTotal Waiting Time:%d\n",totwt);
    printf("\nTotal Turnaround Time:%d\n",tottat);
    printf("\n\nAverage Waiting Time:%f\n",avgwt);
    printf("\nAverage Turnaround Time:%f\n",avgtat);

return 0;
}
