//SHORTEST JOB FIRST ALGORTHIM NON-PRIMITIVE VERSION

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
char p[10][5],temp[5];
int wt[10],bt[10],i,j,n,temp1,at[20],ct[20],tat[20];
float totalwt=0,totaltat=0;
float avgtat=0,avgwt=0;
printf("enter no of processes\n");
scanf("%d",&n);
printf("enter %d number of processes\n",n);
for(i=0;i<n;i++){
scanf("%s",p[i]);
}
printf("enter process Arrival time\n");
for(i=0;i<n;i++){
printf("P%d: ",i);
scanf("%d",&at[i]);
}
printf("enter process burst time\n");
for(i=0;i<n;i++)
{
printf("P%d: ",i);
scanf("%d",&bt[i]);
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(bt[i]>bt[j])
{
temp1=bt[i];
bt[i]=bt[j];
bt[j]=temp1;

temp1=at[i];
at[i]=at[j];
at[j]=temp1;

temp1=ct[i];
ct[i]=ct[j];
ct[j]=temp1;

strcpy(temp,p[i]);
strcpy(p[i],p[j]);
strcpy(p[j],temp);
}
}
}
for(i=0;i<=n;i++){
ct[i]=0;
for(j=0;j<=i;j++)
{

ct[i]=ct[i]+bt[j];
tat[i]=abs(ct[i]-at[i]);
wt[i]=abs(tat[i]-bt[i]);
}
}

printf("p_name\t  Arrival_time\t burst_time\t Completion_time\t TurnAround_time\twaiting_time\n");
for(i=0;i<n;i++){
totalwt=totalwt+wt[i];
totaltat=totaltat+tat[i];
printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
}
avgwt=(totalwt)/i;
avgtat=(totaltat)/i;
printf("Total waiting time=%f\n Total turn around time=%f\n",totalwt,totaltat);
printf("average waiting time=%f\n avg turn around time=%f\n",avgwt,avgtat);

return 0;
}
