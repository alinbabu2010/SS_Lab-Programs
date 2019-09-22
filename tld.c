#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct{
 char dname[10],fname[10][10];
 int fcnt;
}dir[50];
int i,j,k,dcnt,ch;
int main()
{
  char f[30],d[30];
  dcnt=0;
  while(1)
  {
    printf("\n1.Create directory\n2.Create File\n3.Delete File\n4.Search File\n5.Display File\n6.Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
       case  1: printf("Enter the dirctory name\n");
                scanf("%s",dir[dcnt].dname);
                dir[dcnt].fcnt=0;
                printf("\nDirectory created\n");
                dcnt++;
                break;
       case  2: printf("Enter the directory name\n");
                scanf("%s",d);
                for(i=0;i<dcnt;i++)
                {
                  if(strcmp(d,dir[i].dname)==0)
                  {
                    printf("Enter the file name\n");
                    scanf("%s",dir[i].fname[dir[i].fcnt]);
                    printf("\nDirectory created\n");
                    dir[i].fcnt++;
                    break;
                  }
                }
                if(i==dcnt)
                  printf("Directory not found\n");
                break;
       case  3: printf("Enter the directory name\n");
                scanf("%s",d);
                for(i=0;i<dcnt;i++)
                {
                  if(strcmp(d,dir[i].dname)==0)
                  {
                      printf("Enter the file name\n");
                      scanf("%s",f);
                      for(j=0;j<dir[i].fcnt;j++)
                      {
                        if(strcmp(dir[i].fname[j],f)==0)
                        {
                          printf("File %s is deleted\n",f);
                          dir[i].fcnt--;
                          strcpy(dir[i].fname[j],dir[i].fname[dir[i].fcnt]);
                          goto jmp;
                        }
                      }
                      printf("File not found\n");
                      goto jmp;
                  }
                }
                printf("Directory not found\n");
                jmp:break;
       case  4: printf("Enter the directory name\n");
                scanf("%s",d);
                for(i=0;i<dcnt;i++)
                {
                  if(strcmp(d,dir[i].dname)==0)
                  {
                      printf("Enter the file name\n");
                      scanf("%s",f);
                      for(j=0;j<dir[i].fcnt;j++)
                      {
                        if(strcmp(f,dir[i].fname[j])==0)
                        {
                          printf("File %s found\n",f);
                          goto jmp1;
                        }
                      }
                      printf("File not found\n");
                      goto jmp1;
                  }
                }
                printf("Directory not found\n");
                jmp1:break;
        case 5: if(dcnt==0)
                  printf("\nNo directory\n");
                else
                {
                  for(i=0;i<dcnt;i++)
                  {
                    printf("\nDirectories are:\t") ;
                    printf("%s\t",dir[i].dname);
                    printf("Files are:\t");
                    for(k=0;k<dir[i].fcnt;k++)
                    {
                      printf("%s\t",dir[i].fname[k]);
                    }
                    printf("\n");
                  }
                }
                break;
       case  6: exit(0);
                break;
       default: printf("Invalid Option\n");
                break;
    }
  }
  return 0;
}