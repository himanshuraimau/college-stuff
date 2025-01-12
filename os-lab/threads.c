// working of threads in c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


void* threadfun1(void *arg){
    for(int i=0;i<5;i++){
        printf("Thread 1 is running:%d\n",i);
        sleep(1);
    }

}
void *threadfun2(void *arg){
    for(int i=0;i<5;i++){
        printf("Thread 2 is running:%d\n",i);
        sleep(1);
    }

}



int main(){
    pthread_t thread1,thread2;
    if(pthread_create(&thread1,NULL,threadfun1,NULL)!=0){
        printf("error creating the threadl");
        return 1;
    }
    if(pthread_create(&thread2,NULL,threadfun2,NULL)!=0){
        printf("error creating the threadl");
        return 1;
    }
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    printf("Thread Exectuion completed");
}

