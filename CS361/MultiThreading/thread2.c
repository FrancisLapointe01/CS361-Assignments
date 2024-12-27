#include <stdio.h>
#include <pthread.h>

static int counter = 0; //global variable

void *myfunction(void *arg) 
{
        int x = 0;
        printf("%s: start \n", (char *) arg);
        for(int i =0; i< 10000000; i++)
                counter++;
        //printf("%s \t x = %d \n", (char*) arg, x);
        printf("%s: end \n", (char *) arg);
        return NULL;
}

int main(int argc, char *argv[])
{
        pthread_t t1, t2;

        printf("main: beginning (counter = %d) \n", counter);
        pthread_create( &t1, NULL, myfunction, "A");
        pthread_create( &t2, NULL, myfunction, "B");

        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
        printf("main: ending (counter = %d) \n", counter);
        return 0;
}