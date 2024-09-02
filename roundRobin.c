#include<stdio.h>

struct process{
    int id,at,bt,ct,tat,rbt,wt;
}p[10];

int min(int a,int b){
    return (a<b)? a:b;
}

int main(){
    int i,j,n,tq;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the details of process id, arrival time, burst time:\n");
        scanf("%d%d%d",&p[i].id,&p[i].at,&p[i].bt);
        p[i].rbt=p[i].bt;
    }
    printf("Enter the time quantum: ");
    scanf("%d",&tq);
    int flag=0,time=0;
    while(flag<n){
        for(i=0;i<n;i++){
            if(p[i].rbt>0){
                int et=min(tq,p[i].rbt);
                time+=et;
                p[i].rbt-=et;
                if(p[i].rbt<=0){
                    p[i].ct=time;
                    p[i].tat=p[i].ct-p[i].at;
                    p[i].wt=p[i].tat-p[i].bt;
                    flag++;
                }
            }
        }
    }
    int ttat=0,twt=0;
    for(i=0;i<n;i++){
        ttat+=p[i].tat;
        twt+=p[i].wt;
    }
    float atat=(float)ttat/n;
    float awt=(float)twt/n;
    printf("The average turnaround time: %f\n",atat);
    printf("The average waiting time: %f\n",awt);
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    return 0;
}
