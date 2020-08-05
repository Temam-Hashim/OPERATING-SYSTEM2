#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct schedule {
char p[100];
int bt,at,ct,wt,tat;


};
int main(){
int i,j,n;
float avgtat=0;
float avgwt=0;
struct schedule s[20];
printf("enter number of proccess\n");
scanf("%d",&n);

printf("enter arrival time\n");
for(i=0;i<n;i++){
printf("P%d:",i);
scanf("%d",&s[i].at);
}
printf("enter burst time\n");
for(i=0;i<n;i++){
printf("P%d:",i);
scanf("%d",&s[i].bt);
}
for(i=0;i<n;i++){
s[i].wt=0;
s[i].ct=0;
for(j=0;j<=i;j++)
s[i].ct=s[i].ct+s[j].bt;
s[i].tat=s[i].ct-s[i].at;
s[i].wt=s[i].tat-s[i].bt;
}
printf("Proceess\tArrival Time\tBurst time\tcompletion time\tTurnAround time\tWaiting Time\n");
for(i=0;i<n;i++){
avgwt=avgwt+s[i].wt;
avgtat=avgtat+s[i].tat;
printf("\nP%d\t\t%d\t\t\t%d\t\t%d\t\t%d\t\t%d\n",i,s[i].at,s[i].bt,s[i].ct,s[i].tat,s[i].wt);
}
avgwt=avgwt/i;
avgtat=avgtat/i;
printf("\n\nAverage waiting time:%f\n",avgwt);
printf("\nAverage turn around time:%f\n",avgtat);




return 0;
}
