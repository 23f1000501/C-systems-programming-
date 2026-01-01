#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	printf("Initiating system boot process...  \n");

	if ( fork() == 0 )
	{
		execlp("df", "df", "-h", NULL);

		perror("Boot sequence Failed");
	}

	else
	{
		wait(NULL);
		printf("Boot sequence initiated successfully :)\n");
		
	}

	return 0;

}
