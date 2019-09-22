#include<stdio.h>
int burst_time[20],wait_time[20],turn_time[20],P[20],priority[20],i,j,n;
float tturn_time,twait_time,avturn_time,avwait_time;
void sort();
void Wait_Time();
void Turnaround_Time();
void display();
int main()
{
   printf("Enter the number of process\n");
   scanf("%d",&n);
   printf("Enter the Burst time of each process\n");
   for(i=0;i<n;i++)
   {
     printf("P[%d] :",i+1);
     scanf("%d",&burst_time[i]);
     P[i]=i+1;
     printf("Enter the priority of process %d\n",P[i]);
     scanf("%d",&priority[i]);
   }
   sort();
   Wait_Time();
   Turnaround_Time();
   display();
   return 0;
}
void Wait_Time()
{
    wait_time[0]=0;
    for(i=1;i<n;i++)
    {
      for(j=0;j<i;j++)
      {
        wait_time[i]+=burst_time[j];
      }
      twait_time+=wait_time[i];
    }
    avwait_time=twait_time/n;
}
void Turnaround_Time()
{
    for(i=0;i<n;i++)
    {
      for(j=0;j<=i;j++)
      {
        turn_time[i]+=burst_time[j];
      }
      tturn_time+=turn_time[i];
    }
    avturn_time=tturn_time/n;
}
void display()
{
    printf(" Process\t\t\tPriority\t\t\tBurst Time\t\t\tWaiting Time\t\t\tTurnaround Time\n");
    for(i=0;i<n;i++)
    {
       printf(" P[%d]\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n",P[i],priority[i],burst_time[i],wait_time[i],turn_time[i]);
    }
    printf("Averge Waiting Time :%.2f\n",avwait_time);
    printf("Averge Turnaround Time :%.2f\n",avturn_time);
}
void sort()
{
  int temp,temp1,temp2;
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(priority[i]<priority[j])
      {
        temp=burst_time[i];
        burst_time[i]=burst_time[j];
        burst_time[j]=temp;

        temp2=priority[i];
        priority[i]=priority[j];
        priority[j]=temp2;

        temp1=P[i];
        P[i]=P[j];
        P[j]=temp1;
      }
    }
  }
}