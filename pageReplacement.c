#include<stdio.h>
#include<stdlib.h>

void FIFO(int pages[],int p,int frames[],int f){
    int pf=0,flag,index=0;
    for(int i=0;i<f;i++){
        frames[i]=-1;
    }
    for(int i=0;i<p;i++){
        flag=1;
        for(int j=0;j<f;j++){
            if(frames[j]==pages[i]){
                flag=0;
            }
        }
        if(flag){
            pf++;
            frames[index]=pages[i];
            index=(index+1)%f;
        }
    }
    printf("The page fault is %d\n",pf);
}

void LRU(int pages[],int p,int frames[],int f){
    int flag,pf=0,time[f];
    for(int i=0;i<f;i++){
        frames[i]=-1;
        time[i]=0;
    }
    for(int i=0;i<p;i++){
        flag=0;
        int foundIndex=0;
        for(int j=0;j<f;j++){
            if(frames[j]==pages[i]){
                flag=1;
                foundIndex=j;
            }
        }
        if(flag){
            time[foundIndex]=i;
        }else{
            pf++;
            int minTime=p;
            int lruIndex=-1;
            for(int k=0;k<f;k++){
                if(time[k]<minTime){
                    minTime=time[k];
                    lruIndex=k;
                }
            }
            frames[lruIndex]=pages[i];
            time[lruIndex]=i;

        }
    }
    printf("The page fault is %d\n",pf);
}

void LFU(int pages[],int p,int frames[],int f){
    int pf = 0, flag;
    int frequency[f], time[f];
    for (int i = 0; i < f; i++) {
        frames[i] = -1;
        frequency[i] = 0;
        time[i] = -1;
    }
    for (int i = 0; i < p; i++) {
        flag = 0;
        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                flag = 1;
                frequency[j]++;
                time[j]=i;
                break;
            }
        }
        if (!flag) {
            pf++;
            int minFreq = p, lfuIndex = -1;
            for (int j = 0; j < f; j++) {
                if (frequency[j] < minFreq || (frequency[j] == minFreq && time[j] < time[lfuIndex])) {
                    minFreq = frequency[j];
                    lfuIndex = j;
                }
            }
            if (lfuIndex == -1) {
                lfuIndex = 0;
            }
            frames[lfuIndex] = pages[i];
            frequency[lfuIndex] = 1;
            time[lfuIndex] = i;
        }
    }
    printf("LFU - The number of page faults is %d\n", pf);
}
int main(){
    int ch,p,f;
    printf("Enter the no of frames:\t");
    scanf("%d",&f);
    printf("Enter the no of page requests:\t");
    scanf("%d",&p);
    int pages[p],frames[f];
    printf("Enter the page string:\n");
    for(int i=0;i<p;i++){
        scanf("%d",&pages[i]);
    }
    while(1){
        printf("-----MENU-----\n");
        printf("1.FIFO\n2.LRU\n3.LFU\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                FIFO(pages,p,frames,f);
                break;
            case 2:
                LRU(pages,p,frames,f);
                break;
            case 3:
                LFU(pages,p,frames,f);
                break;
            case 4:
                exit(0);
        }
    }
}
