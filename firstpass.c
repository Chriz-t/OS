#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int locctr,start,len;
    char label[10],opcode[10],operand[10],code[10],mnemonic[10];
    FILE *fp1,*fp2,*fp3,*fp4;
    fp1=fopen("input.txt","r");
    fp2=fopen("symtab.txt","w");
    fp3=fopen("optab.txt","r");
    fp4=fopen("inter.txt","w");

    fscanf(fp1,"%s%s%s",label,opcode,operand);

    if(strcmp(opcode,"START")==0){
        start=atoi(operand);
        locctr=start;
        fprintf(fp4,"\t%s\t%s\t%s\n",label,opcode,operand);
        fscanf(fp1,"%s%s%s",label,opcode,operand);
    }else{
        locctr=0;
    }
    while(strcmp(opcode,"END")!=0){
        fprintf(fp4,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        if(strcmp(label,"**")!=0){
            fprintf(fp2,"%s\t%d\n",label,locctr);
        }
        fscanf(fp3,"%s\t%s",code,mnemonic);
        while(strcmp(code,"END")!=0){
            if(strcmp(opcode,code)==0){
                locctr+=3;
                break;
            }
            fscanf(fp3,"%s\t%s",code,mnemonic);
        }
        if(strcmp(opcode,"BYTE")==0)
            locctr++;
        else if(strcmp(opcode,"RESB")==0)
            locctr+=atoi(operand);
        else if(strcmp(opcode,"WORD")==0)
            locctr+=3;
        else if(strcmp(opcode,"RESW")==0)
            locctr+=3*atoi(operand);
        fscanf(fp1,"%s%s%s",label,opcode,operand);
    }
    fprintf(fp4,"%d\t%s\t%s\t%d\n",locctr,label,opcode,start);
     fclose(fp1);
     fclose(fp2);
     fclose(fp3);
     fclose(fp4);
     printf("The lenght of the prgm is %d",locctr-start);
}
