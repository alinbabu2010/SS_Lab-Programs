//Implementation of Symbol Table//
//Alin Babu,7,R5//
//File name : symtable.c//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 11             //Maximum size of table//
char l[10];
struct symb         //Structure array for storing address and label//
{
    int add;
    char label[10];
}sy[50];
void search();
int main()
{
    int a[50],num,key,i,ch;
    char ans;
    int create(int);
    void lprob(int [],int,int);
    void display(int []);
    for(i=0;i<MAX;i++)
    a[i]=0;
    while(1)
    {
        printf("\n1.Create a symbol table\n2.Search in the symbol table\n3.Exit\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
                case 1: printf("\nEnter the address\n");
                        scanf("%d",&num);
                        key=create(num);
                        printf("\nEnter The label\n");
                        scanf("%s",l);
                        lprob(a,key,num);
                        display(a);
                        break;
                case 2: search();
                        break;
                case 3: exit(0);
                        break;
               default: printf("Invalid Option");
        }
    }
    return 0;
}
int create(int num)                //Hashing Function to generate key//
{
    int key;
    key=num%11;
    return key;
}
void lprob(int a[MAX],int key,int num)      //Insertion of address and label in hash table using linear probing//
{
    int flag,i,count=0;
    void display(int a[]);
    flag=0;
    if(a[key]==0)
    {
        a[key]=num;
        sy[key].add=num;
        strcpy(sy[key].label,l);
    }
    else
    {
        i=0;
        while(i<MAX)
        {
                if(a[i]!=0)
                count++;
                i++;
        }
        if(count==MAX)
        {
                printf("\nHash table is full");
                display(a);
                exit(1);
        }
        for(i=key+1;i<MAX;i++)
         if(a[i]==0)
         {
                a[i]=num;
                flag=1;
                sy[key].add=num;
                strcpy(sy[key].label,l);
                break;
         }
        for(i=0;i<key && flag==0;i++)
        if(a[i]==0)
        {
                a[i]=num;
                flag=1;
                sy[key].add=num;
                strcpy(sy[key].label,l);
                break;
        }
    }
}
void display(int a[MAX])                 // Function to display the symbol table//
{
    int i;
    printf("\nThe Symbol Table is");
    printf("\nKey\tAddress\tLabel");
    for(i=0;i<MAX;i++)
        printf("\n%d\t%d\t%s",i,sy[i].add,sy[i].label);
}
void search()                           // Function to search the symbol table for the label address//
{
    char la[10];
    int set=0,s;
    int j,i;
    printf("enter the label: ");
    scanf("%s",la);
    for(i=0;i<MAX;i++)
    {
        if(sy[i].add!=0)
        {
                if(strcmp(sy[i].label,la)==0)
                {
                        set=1;
                        s=sy[i].add;
                }
        }
    }
    if(set==1)
    printf("\nThe label --%s-- is present in the symbol table at address:%d\n",la,s);
    else
    printf("\nThe label is not present in the symbol table\n");
}