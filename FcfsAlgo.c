#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){

int flag=0,n,i,j,a,b,c;
int bt[20],wt[20],tat[20],at[20],ct[i]; 
float avgwt=0,avgtat=0;
//enter number of proccess 
printf("enter the number of poccess you want to excute\n");
scanf("%d",&n);
//arrival time of each proccess
printf("enter the process arrival time\n");
for(i=0;i<n;i++){
printf("p[%d]:",i+1);
scanf("%d",&at[i]);
}
//enter burst time of each proccess
printf("enter the process burst time\n");
for(i=0;i<n;i++){
printf("p[%d]:",i+1);
scanf("%d",&bt[i]);
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
    printf("\nProcess\t\tArrival time\tBurst Time\tcompletion time\tTurnaround Time\tWaiting Time\n");
 
    //calculating turnaround time
    for(i=0;i<n;i++)
      {
         avgwt=(avgwt+wt[i]);
        avgtat=(avgtat+tat[i]);

        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
 
    avgwt=avgwt/i;
   avgtat=avgtat/i;
    printf("\n\nAverage Waiting Time:%f\n",avgwt);
    printf("\nAverage Turnaround Time:%f\n",avgtat);

return 0;
}

 
