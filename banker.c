//Implementation of banker's algorithm//
//Alin Babu,7,R5//
//File name:bankers.c//
#include<stdio.h>
#include <stdbool.h>
int i,k,j;
bool found;
int n,m,safeSeq[50];
// Function to find the system is in safe state or not//
bool issafe(int max[n][m],int allocation[n][m],int work[m],int need[n][m])          // Function to find the system is in safe state or not//
{
  int count=0,finish[n];
  for (i=0;i<n;i++)
    finish[i]=0;
  while(count<n)
  {
    for (i=0;i<n;i++)
    {
       if(finish[i]==0)
       {
         for(j=0;j<m;j++)
           if(need[i][j]>work[j])
             break;
         if(j==m)
         {
             for (k=0;k<m;k++)
               work[k] += allocation[i][k];
             safeSeq[count++]=i;
             finish[i]=1;
             found=true;
         }
       }
    }
    if(found==false)
    {
         printf("\nSystem is not in safe state\n");
         return false;
    }
  }
  printf("\nSystem is in safe state\n");
  printf("Safe sequence is ");
  for (k=0;k<n;k++)
      printf("%d ",safeSeq[k]);
  printf("\n");
  return true;
}
int main()
{
  printf("Enter the no: of process\n");
  scanf("%d",&n);
  printf("Enter the no: of resources\n");
  scanf("%d",&m);
  int available[m],max[n][m],allocation[n][m],work[m],need[n][m],instance[m];
  printf("Enter the instances of resources\n");
  for(i=0;i<m;i++)
   scanf("%d",&instance[i]);
  printf("Enter the maximum resources that can be allocated to processes\n");                  // Maximum resources allocated to processes //
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
      scanf("%d",&max[i][j]);
  }
  printf("Enter the resources allocated to processes\n");                                      // Resources allocated to processes //
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
      scanf("%d", &allocation[i][j]);
  }
  printf("Available processes\n");                                                             // Available instances of resources //
  for(i=0;i<m;i++)
  {
    available[i]=0;
    for(j=0;j<n;j++)
      available[i]+=allocation[j][i];
    available[i]=instance[i]-available[i];
    printf("%d ",available[i]);
  }
  printf("\nNeed of each process\n");
  for ( i = 0 ; i < n ; i++)                                                                   // To calculate need and display //
  {
    for ( j = 0 ; j < m ; j++)
    {
      need[i][j] = max[i][j] - allocation[i][j];
      printf("%d ", need[i][j]);
    }
    printf("\n");
  }
  //Intiallize work///
  for ( i = 0 ; i < m ; i++ )
      work[i] = available[i];
  issafe(max,allocation,work,need);
  return 0;
}