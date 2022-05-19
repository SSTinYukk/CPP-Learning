#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_PTHREAD_NUM 10
#define M 32            //buffer大小
#define CONSUMER_NUM    3
#define PRODUCER_NUM    5
#define P(x)     sem_wait(&x)
#define V(x)    sem_post(&x)

pthread_t consumer_id[MAX_PTHREAD_NUM]; //tid数组
pthread_t producer_id[MAX_PTHREAD_NUM];

int in = 0;         
int out = 0;             

int buff[M] = {0};     //缓冲初始化为0， 开始时没有产品

sem_t empty_sem;         //同步信号量，当满了时阻止生产者放产品
sem_t full_sem;         //同步信号量，当没产品时阻止消费者消费
pthread_mutex_t mutex;  //互斥信号量， 一次只有一个线程访问缓冲

void print()
{
    int i;
    for(i = 0; i < M; i++)
        printf("%d ", buff[i]);
    printf("\n");
}


void *producer(void *data)
{
    for(;;)
    {
        sleep(1);

        P(empty_sem);
        pthread_mutex_lock(&mutex);

        in = in % M;
        printf("(+)produce a product. buffer:");

        buff[in] = 1;
        print();
        ++in;

        pthread_mutex_unlock(&mutex);
        V(full_sem);
    }
}

void *consumer(void *data)
{
    for(;;)
    {
        sleep(2);

        P(full_sem);
        pthread_mutex_lock(&mutex);

        out = out % M;
        printf("(-)consume a product. buffer:");

        buff[out] = 0;
        print();
        ++out;

        pthread_mutex_unlock(&mutex);
        V(empty_sem);
    }
}

void sem_mutex_init()
{

    int init1 = sem_init(&empty_sem, 0, M);
    int init2 = sem_init(&full_sem, 0, 0);
    if( (init1 != 0) && (init2 != 0))
    {
        printf("sem init failed \n");
        exit(1);
    }
    int init3 = pthread_mutex_init(&mutex, NULL);
    if(init3 != 0)
    {
        printf("mutex init failed \n");
        exit(1);
    }
    
}
int main()
{
    int ret;

    sem_mutex_init();
    
    for(int i=0;i<PRODUCER_NUM;i++){
         ret = pthread_create(&producer_id[i], NULL, producer, NULL);
        if(ret != 0)
        {
        printf("consumer creation failed \n");
        exit(1);
        }
    }
    for(int i=0;i<CONSUMER_NUM;i++){
         ret = pthread_create(&consumer_id[i], NULL, consumer, NULL);
        if(ret != 0)
        {
        printf("consumer creation failed \n");
        exit(1);
        }
    }

    for(int i=0;i<PRODUCER_NUM;i++){
        pthread_join(producer_id[i],NULL);
    }

    for(int i=0;i<CONSUMER_NUM;i++){
        pthread_join(producer_id[i],NULL);
    }


    exit(0);
}