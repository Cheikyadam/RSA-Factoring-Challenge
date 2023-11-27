#include <stdio.h>
#include <math.h>

/**
 * isprime - to check if a number is a prime or not
 * @n: the number
 *
 * Return: 0 or 1
 */
int isprime(unsigned long int n)
{
	unsigned long int i = 0;
	unsigned long int it = 0;
	int count = 2;

	if (n == 2 || n == 3)
		return (1);
	it = sqrt(n);
	for (i = 2; i <= it && count < 3; i++)
	{
		if (n % i == 0)
			count++;
	}
	if (count > 2)
		return (0);
	return (1);
}


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
	unsigned long int j = 0;
	int found = 0;
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
		found = 0;
		for (i = 2; i <= it; i++)
		{
			if ((n % i) == 0 && (isprime(i) == 1))
			{
				j = i;
				for ( ; j <= it; j++)
				{
					if ((n % j == 0) && (isprime(j) == 1) && (i * j) == n)
					{
						found = 1;
						break;
					}
				}
			}
			if (found == 1)
				break;
		}
		printf("%lu=%lu*%lu\n", n, j, i);
	}

	return (0);

}
