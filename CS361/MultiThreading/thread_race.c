#include <stdio.h>
#include <pthread.h>

int counter = 0;

void *worker1(void *arg)
{
        counter = 0;
	while (counter < 10)
                counter++;
	printf("A wins!");
        return NULL;
}

void *worker2(void *arg)
{
        counter = 0;
	while (counter > -10)
                counter--;
	printf("B wins!");
        return NULL;
}

int main(int argc, char *argv[])
{
        pthread_t p1, p2;
        printf("Initial value: %d\n", counter);

        pthread_create(&p1, NULL, worker1, NULL);
        pthread_create(&p2, NULL, worker2, NULL);
        pthread_join(p1, NULL);
        pthread_join(p2, NULL);
        printf("Final value : %d\n", counter);
        return 0;
}