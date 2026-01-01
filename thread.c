#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void* thread_function(void* arg) 
{
	char* message = (char*)arg;
	printf("Thread: starting.... Received message: %s\n", message);

	sleep(5);

	printf("Thread work finished.\n");

	return NULL;

}

int main()
{
	pthread_t my_thread;
	char* msg = "Hello from the main process!";

	printf("Main: Creating the thread...\n");

	if ( pthread_create(&my_thread, NULL, thread_function, (void*)msg) )
	{
		fprintf(stderr, "Error creating thread  :(\n");
		return 1;
	}

	printf("Main: Thread created. I am going to wait for it to finish :p\n");

	pthread_join( my_thread, NULL );

	printf( "Main: Thread has returned :). Exiting the process now.\n" );
	return 0;

}
