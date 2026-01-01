#include <stdio.h>
#include <pthread.h>

long long counter = 0;

void* increment_task(void* arg)
{
	for ( int i = 0; i < 1000000; ++i )
	{
		++counter;
	}
	return NULL;

}

int main()
{
	pthread_t t1, t2;

	pthread_create( &t1, NULL, increment_task, NULL );

	pthread_create( &t2, NULL, increment_task, NULL );

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("Expected 2000000\n");
	printf("Actual %lld\n", counter);

	return 0;

}
