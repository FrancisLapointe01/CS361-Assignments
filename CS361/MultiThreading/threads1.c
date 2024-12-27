#include <stdio.h>
#include <pthread.h>

void *myfunction(void *arg) 
{
        printf("%s \n", (char *) arg);
        return NULL;
}

int main(int argc, char *argv[])
{
        pthread_t t1, t2;
        int rc;
        printf("main: beginning\n");
        pthread_create( &t1, NULL, myfunction, "A");
        pthread_create( &t2, NULL, myfunction, "B");

//      pthread_join(t1, NULL);
//      pthread_join(t2, NULL);
        printf("main: ending\n");
        return 0;
}