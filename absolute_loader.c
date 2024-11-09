#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[50],addr[10];
    int i,j,hexaddr;
    FILE *fp1, *fp2;
    fp1 = fopen("input1.txt", "r");
    fp2 = fopen("output1.txt", "w");
    do{
        fscanf(fp1,"%s",input);
        if(input[0]=='T'){
            for(i=1,j=0;i<=6;i++,j++)
                addr[j]=input[i];
            addr[j]='\0';
            hexaddr=(int)strtol(addr,NULL,16);//converts string to hexadecimal
            i=9;
            while(input[i]!='\0'){
                fprintf(fp2,"%x\t\t%c%c\n",hexaddr,input[i],input[i+1]);
                hexaddr++;
                i+=2;
            }
        }
    }while(!feof(fp1));
    fclose(fp1);
    fclose(fp2);
    printf("FINISHED\n");
}
