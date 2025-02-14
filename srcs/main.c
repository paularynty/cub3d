#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	(void)argv;
	while (i++ < argc)
		printf("hello world\n");
	return (0);
}