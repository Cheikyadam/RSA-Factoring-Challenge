#include <stdio.h>

/**
 * main - factors
 * @argc: number of args
 * @argv: args
 *
 * Return: 0 or -1 (Failed)
 */

int main(int argc, char **argv)
{
	unsigned long int n;
	unsigned long int i = 0;
	unsigned long int it = 0;
	FILE *fd = NULL;

	if (argc != 2)
		return (-1);
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		return (-1);
	while (fscanf(fd, "%lu\n", &n) != EOF)
	{
		it  = n / 2;
		for (i = 2; i <= it; i++)
		{
			if (n % i == 0)
				break;
		}
		printf("%lu=%lu*%lu\n", n, n / i, i);
	}

	return (0);

}
