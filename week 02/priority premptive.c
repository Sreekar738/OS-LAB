#include <stdio.h>

int main(){

int n,i,time=0,completed=0;
int bt[10],at[10],pr[10];
int rt[10],ct[10],tat[10],wt[10];
int highest,min_pr;

printf("Enter number of processes:");
scanf("%d",&n);

for(i=0;i<n;i++){
    printf("\nProcess %d\n",i+1);
    printf("Arrival Time:");
    scanf("%d",&at[i]);
    printf("Burst Time:");
    scanf("%d",&bt[i]);
    printf("Priority:");
    scanf("%d",pr[i]);
    rt[i]=bt[i];
}
while(completed!=n){
    highest=-1;
    min_pr=999;
    for(i=0;i<n;i++){
        if(at[i]<=time&&rt[i]>0&&pr[i]<min_pr){
            min_pr=pr[i];
            highest=i;
        }
    }
    if(highest==-1){
        time++;
        continue;
    }
    rt[highest]--;
    time++;
    if(rt[highest]==0){
        completed++;
        ct[highest]=time;
        tat[highest]=ct[highest]-at[highest];
        wt[highest]=tat[highest]-bt[highest];
    }
}
printf("\nProcess\tAT\tBT\tPR\tCT\tAT\tWT\n");
for(i=0;i<n;i++){
    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
}

}
