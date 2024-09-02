#include<stdio.h>
#include<stdlib.h>

int dist(int a,int b){
    int c=abs(a-b);
    return c;
}

void FCFS(int req[],int n,int head){
    int hm=0;
    for(int i=0;i<n;i++){
        if(i==0){
            hm+=dist(head,req[0]);
            continue;
        }
        hm+=dist(req[i-1],req[i]);
    }
    printf("The head movement is: %d\n",hm);
}

void SCAN(int req[],int n,int head,int max){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(req[j]>req[j+1]){
                int temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }

    int hm=0,first=1,count=0;
    for(int i=0;i<n;i++){
        if (req[i] > head) {
            if (first) {
                hm += dist(head, req[i]);
                first = 0;
            } else {
                hm += dist(req[i - 1], req[i]);
            }
        } else {
            count++;
        }
    }
    if (req[n - 1] > head) {
        hm += dist(req[n - 1], max);
    }
    for(int i=count-1;i>=0;i--){
        if(i==count-1){
            hm+=dist(req[i],max);
        }else{
            hm+=dist(req[i],req[i+1]);
        }
    }
    printf("The head movement is: %d\n",hm);
}

void CSCAN(int req[],int n,int head,int max){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(req[j]>req[j+1]){
                int temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }

    int hm=0,first=1,count=0;
    for(int i=0;i<n;i++){
        if (req[i] > head) {
            if (first) {
                hm += dist(head, req[i]);
                first = 0;
            } else {
                hm += dist(req[i - 1], req[i]);
            }
        } else {
            count++;
        }
    }
    if (req[n - 1] > head) {
        hm += dist(req[n - 1], max);
    }
    if(count!=0){
        for(int i=0;i<count;i++){
        if(i==0){
            hm+=max+req[i];
        }else{
            hm+=dist(req[i-1],req[i]);
        }
    }
    }
    printf("The head movement is: %d\n",hm);

}

int main(){
    int n,head,max;
    printf("Enter the no of requests:\t");
    scanf("%d",&n);
    int req[n];
    printf("Enter the max value:\t");
    scanf("%d",&max);
    printf("Enter the current head position:\t");
    scanf("%d",&head);
    printf("Enter the requets:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    while(1){
        int ch;
        printf("-----MENU-----\n");
        printf("1.FCFS\n2.SCAN\n3.CSCAN\n4.Exit\n"); 
        scanf("%d",&ch);
        switch(ch){
            case 1:
                FCFS(req,n,head);
                break;
            case 2:
                SCAN(req,n,head,max);
                break;
            case 3:
                CSCAN(req,n,head,max);
                break;
            case 4:
                exit(0);
        }
    }

}
