#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


int main()
{
	pid_t pid;

	pid = fork();


	if ( pid < 0 )
	{
		perror("Fork Failed\n");
		exit(EXIT_FAILURE);
	}

	else if ( pid == 0 )
	{
		printf("Yo this is the child process\n");
	}

	else
	{
		printf("Ja Ja Ja thisis the parent motherfucker\n");
	}

	return 0;

}


