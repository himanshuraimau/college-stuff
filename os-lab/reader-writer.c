// reader-writer problem
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>

int rcount = 0;
int wcount = 0; 
sem_t x,y;
pthread_t tid;
pthread_t wthread[100],rthread[100];


void* reader(void *param){
    sem_wait(&x);
    rcount++;
    if(rcount==1) sem_wait(&y);
    sem_post(&x);
    printf("\nReader %d is inside\n", rcount);
    sleep(5);
    sem_wait(&x);
    rcount--;
    if(rcount==0) sem_post(&y);
    sem_post(&x);
    printf("\nReader %d is leaving\n", rcount+1);
    return NULL;
}

void *writer(void *param){
    printf("\nWriter is trying to enter\n");
    sem_wait(&y);
    wcount++;
    printf("Writer %d has entered\n", wcount);
    sleep(5);
    wcount--;
    sem_post(&y);
    printf("\nWriter %d is leaving\n", wcount+1);
    return NULL;
}

int main(){
    int rcnt,wcnt,i;
    printf("\nEnter the number of readers: ");
    scanf("%d",&rcnt);
    printf("\nEnter the number of writers: ");
    scanf("%d",&wcnt);
    
    sem_init(&x,0,1);
    sem_init(&y,0,1);
    for(int i=0;i<rcnt;i++){
        pthread_create(&rthread[i],NULL,reader,NULL);
    }
    for(int i=0;i<wcnt;i++){
        pthread_create(&wthread[i],NULL,writer,NULL);
    }
    for(int i=0;i<rcnt;i++){
       pthread_join(rthread[i],NULL);
    }
    for(int i=0;i<wcnt;i++){
        pthread_join(wthread[i],NULL);
    }
}
