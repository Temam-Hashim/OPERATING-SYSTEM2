#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct SJF{
int at,bt,tat,wt,ct;
};

int main(){
int Ttat=0,Twt=0,i,j,n;
float avgtat,avgwt;
struct SJF s[20],temp;
printf("Enter Number Of Proccess\n");
scanf("%d",&n);
printf("Enter arrival time of each proccess\n");
for(i=0;i<n;i++){
printf("p[%d]:",i+1);
scanf("%d",&s[i].at);
}
printf("Enter burst time\n");
for(i=0;i<n;i++){
printf("p[%d]:",i+1);
scanf("%d",&s[i].bt);
}

for(i=0;i<n;i++){
for(j=i+1;j<n;j++){

if(s[i].bt>s[j].bt){
temp=s[i];
s[i]=s[j];
s[j]=temp;

}
}
}
temp.wt=0;
for(i=0;i<=n;i++){
s[i].wt=0;
s[i].ct=0;
for(j=0;j<=i;j++)
s[i].ct=s[i].ct+s[j].bt;
s[i].tat=abs(s[i].ct-s[i].at);
s[i].wt=abs(s[i].tat-s[i].bt);

Ttat=Ttat+s[i].tat;
Twt=Twt+s[i].wt;
}
printf("\nProccess\t Arrival-time\t Burst-time\t Completion-time\t TurnAround-time\t Waiting-time\n");
for(i=0;i<n;i++){
printf("p[%d]\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",i+1,s[i].at,s[i].bt,s[i].ct,s[i].tat,s[i].wt);
avgwt=(float)Twt/i;
avgtat=(float)Ttat/i;
}
printf("\nTotal Waiting Time: %d\n ",Twt);
printf("\nTotal Turn around Time: %d\n",Ttat);
printf("\nAverage Waiting Time: %f\n ",avgwt);
printf("\naverage Turn around Time: %f\n ",avgtat);



return 0;
}
