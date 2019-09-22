//Round Robin Scheduling//
//Alin Babu,7,R5//
#include<stdio.h>
int burst_time[20],wait_time[20],turn_time[20],i,j,n;
int rt[20],arrival_time[20],time_quantum;
float avturn_time,avwait_time,tturn_time,twait_time;
void WaitTurnaround_Time();
void display();
int main()
{
   printf("Enter the number of process\n");
   scanf("%d",&n);
   printf("Enter the time quantum\n");
   scanf("%d",&time_quantum);
   printf("Enter the Burst time and Arrival Time of each process\n");
   for(i=0;i<n;i++)
   {
     printf("P[%d] :",i+1);
     scanf("%d\t",&burst_time[i]);
     scanf("%d",&arrival_time[i]);
     rt[i]=burst_time[i];                                                   //For Temporary Storage of burst time for calculation//
   }
   WaitTurnaround_Time();
   display();
   return 0;
}
void WaitTurnaround_Time()                                                  //Function to calculate Waiting Time and Turn Around Time//
{
    int time,remain,flag;
    remain=n;
    for(time=0,i=0;remain!=0;)
    {
       if(rt[i]<=time_quantum && rt[i]>0)
       {
         time+=rt[i];
         rt[i]=0;
         flag=1;
       }
       else if(rt[i]>0)
       {
          rt[i]-=time_quantum;
          time+=time_quantum;
       }
       if(rt[i]==0 && flag==1)
       {
         remain--;
         turn_time[i]=time-arrival_time[i];
         wait_time[i]=time-arrival_time[i]-burst_time[i];
         twait_time+=wait_time[i];
         tturn_time+=turn_time[i];
         flag=0;
      }
      if(i==n-1)
        i=0;
      else if(arrival_time[i+1]<=time)
        i++;
      else
        i=0;
    }
    avwait_time=twait_time/n;
    avturn_time=tturn_time/n;
}
void display()                                                         //To display  waiting time,turnaround time,averge waiting time and turnaround time//
{
    printf(" Process\t\tBurst Time\t\tArrival Time\t\tWaiting Time\t\tTurnaround Time\n");
    for(i=0;i<n;i++)
    {
       printf(" P[%d]\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1,burst_time[i],arrival_time[i],wait_time[i],turn_time[i]);
    }
    printf("Averge Waiting Time :%.2f\n",avwait_time);
    printf("Averge Turnaround Time :%.2f\n",avturn_time);
}