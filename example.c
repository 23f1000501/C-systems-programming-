#include <stdio.h>

int main()
{

	int x = 0b0;

	for ( int i = 0; i < 10; i++)
	{
		x += 1;
		printf("%b\n", x);
	}

	return 0;

}
