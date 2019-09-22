/*Implementation of Pass 1 of an assembler*/
//Alin Babu,7,R5//
//File name : pass1.c//
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
        FILE *f1,*f2,*f3,*f4;
        int LOCCTR,sa,l,op1,o,len;      //LOCCTR-Location Counter,sa-Starting address,//
        char m1[20],la[20],op[20],otp[20];  //m1-Mnemonic opcode,la-Label,op-Operand,otp-Mnemonic opcode in OPTAB//
        f1=fopen("input.txt","r");             //Input file open//
        f3=fopen("symtab.txt","w");           //Symbol table file open//
        fscanf(f1,"%s %s %d",la,m1,&op1);
        printf("\nIntermediate Code\n");
        if(strcmp(m1,"START")==0)         //Checking whether the opcode equal to start//
        {
                sa=op1;
                LOCCTR=sa;
                f4=fopen("output.txt","w");
                fprintf(f4,"\t%s\t%s\t%d\n",la,m1,op1);
                printf("\n\t%s\t%s\t%d\n",la,m1,op1);
        }
        else
                LOCCTR=0;
        fscanf(f1,"%s %s",la,m1);
        while(!feof(f1))                  //Loop until the end of file//
        {
                fscanf(f1,"%s",op);
                fprintf(f4,"\n%d\t%s\t%s\t%s\n",LOCCTR,la,m1,op);
                printf("\n%d\t%s\t%s\t%s\n",LOCCTR,la,m1,op);
                if(strcmp(la,"-")!=0)    //Search SYMTAB for label//
                {
                        fprintf(f3,"\n%d\t%s\n",LOCCTR,la);
                }
                f2=fopen("optab.txt","r");
                fscanf(f2,"%s %d",otp,&o);
                //Searching OPTAB for OPCODE//
                while(!feof(f2))
                {
                        if(strcmp(m1,otp)==0)
                        {
                                LOCCTR=LOCCTR+3;
                                break;
                        }
                        fscanf(f2,"%s %d",otp,&o);
                }
                fclose(f2);
                if(strcmp(m1,"WORD")==0)
                {
                         LOCCTR=LOCCTR+3;
                }
                else if(strcmp(m1,"RESW")==0)
                {
                        op1=atoi(op);
                        LOCCTR=LOCCTR+(3*op1);
                }
                else if(strcmp(m1,"BYTE")==0)
                {
                        if(op[0]=='X')
                                LOCCTR=LOCCTR+1;
                        else
                        {
                                len=strlen(op)-2;
                                LOCCTR=LOCCTR+len;
                        }
                }
                else if(strcmp(m1,"RESB")==0)
                {
                        op1=atoi(op);
                        LOCCTR=LOCCTR+op1;
                }
                fscanf(f1,"%s%s",la,m1);
        }
        if(strcmp(m1,"END")==0)
        {
                printf("\n\nProgram length = %d\n",LOCCTR-sa);    //Program length=Location Counter-Starting address//
        }
        fclose(f1);
        fclose(f3);
        fclose(f4);
}