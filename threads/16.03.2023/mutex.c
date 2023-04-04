#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int mail = 0;
pthread_mutex_t mutex;

void *rot()
{
   for(int i =0; i<1000000; i++)
   {
    pthread_mutex_lock(&mutex);
    mail++;
    pthread_mutex_unlock(&mutex);
   }
}

int main ()
{
    pthread_t t1,t2;
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&t1,NULL, &rot,NULL);
    pthread_create(&t2,NULL, &rot,NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&mutex);

    printf("number of mails are %d\n", mail);

    return 0;
}