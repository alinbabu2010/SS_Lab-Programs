//Implementation of dinning philosopher problem//
//Alin Babu,7,R5//
//File Name : dphilosopher.c//
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (ph_num+4)%N
#define RIGHT (ph_num+1)%N
sem_t mutex;
sem_t S[N];
void * philospher(void *num);
void take_fork(int);
void put_fork(int);
void test(int);
int state[N];
int phil_num[N]={0,1,2,3,4};   //Number of producers in array//
int main()
{
        int i;
        pthread_t thread_id[N];
        sem_init(&mutex,0,1);
        for(i=0;i<N;i++)
                sem_init(&S[i],0,0);          //semaphore initiallization//
        for(i=0;i<N;i++)
        {
                pthread_create(&thread_id[i],NULL,philospher,&phil_num[i]);            // philosopher thread creation //
                printf("Philosopher %d is thinkingn\n",i+1);
        }
        for(i=0;i<N;i++)
                pthread_join(thread_id[i],NULL);
}
void *philospher(void *num)   //Function for philosopher//
{
        while(1)
        {
                int *i = num;
                sleep(1);
                take_fork(*i);
                sleep(0);
                put_fork(*i);
        }
}
void take_fork(int ph_num)    //Function to take chopsticks if available//
{
        sem_wait(&mutex);
        state[ph_num] = HUNGRY;
        printf("Philosopher %d is Hungry\n",ph_num+1);
        test(ph_num);
        sem_post(&mutex);
        sem_wait(&S[ph_num]);
        sleep(1);
}
void test(int ph_num)      //Function to check  left and right chopsticks are free//
{
        if (state[ph_num] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
        {
                state[ph_num] = EATING;
                sleep(2);
                printf("Philosopher %d takes fork %d and %d\n",ph_num+1,LEFT+1,ph_num+1);
                printf("Philosopher %d is Eating\n",ph_num+1);
                sem_post(&S[ph_num]);
        }
}
void put_fork(int ph_num)  //Function to put chopsticks after eating//
{
        sem_wait(&mutex);
        state[ph_num] = THINKING;
        printf("Philosopher %d putting fork %d and %d down\n",ph_num+1,LEFT+1,ph_num+1);
        printf("Philosopher %d is thinking\n",ph_num+1);
        test(LEFT);
        test(RIGHT);
        sem_post(&mutex);
}