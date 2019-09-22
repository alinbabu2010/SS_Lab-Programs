//Implementation of SCAN disk scheduling//
//Alin Babu,7,R5//
//File name:scan.c//
#include<stdio.h>
int n,head,d[70],i,pos;  // head-head point of the disk , pos-position of the head //
void sort(int d[],int n);
int findHeadPos(int d[],int p,int q,int head);
void scan(int A[],int p,int q,int head);
int main()
{
        printf("Enter number of disk scheduling you want to do \n");
        scanf("%d",&n);
        printf("Enter head \n");
        scanf("%d",&head);
        d[0]=head;
        for(i=1;i<=n;i++)
        {
          printf("Enter the position \n");
          scanf("%d",&d[i]);
        }
        sort(d,n);
        pos=findHeadPos(d,0,n,head);
        printf("Order of SCAN\n");
        scan(d,0,n,pos);
        return 0;
}
void sort(int d[n],int n)              //Function for sorting the access points//
{
        int temp,j;
        for(j=0;j<=n;j++)
          for(i=0;i<n-j;i++)
           if(d[i]>d[i+1])
           {
                temp=d[i];
                d[i]=d[i+1];
                d[i+1]=temp;
           }
}
int findHeadPos(int d[],int p,int q,int head)    //Function to find the position of the disk head//
{
        int mid;
        mid=(p+q)/2;
        if(d[mid]==head)
          return mid;
        else if(d[mid]<head)
          return findHeadPos(d,mid+1,q,head);
        else
          return findHeadPos(d,p,mid-1,head);
}
void scan(int A[n],int p,int q,int pos)      //Function for SCAN disk scheduling order//
{
        int thead=0;
        if(A[pos]-A[pos]-1<A[pos+1]-A[pos])
        {
          for(i=pos;i>=p;i--)
            printf("%d ",A[i]);
          thead=thead+abs(A[pos]-A[i-1]);
          for(i=pos+1;i<=q;i++)
            printf("%d ",A[i]);
          thead=thead+A[q];
        }
        else
        {
          for(i=pos;i<=q;i++)
            printf("%d ",A[i]);
          thead=thead+abs(A[pos]-A[q]);
          for(i=pos-1;i>=p;i--)
            printf("%d ",A[i]);
          thead=thead+A[q];
        }
        printf("\nTotal head movement : %d\n",thead);
}