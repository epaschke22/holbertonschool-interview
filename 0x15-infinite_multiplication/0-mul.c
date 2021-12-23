#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * _strlen - returns string length, and checks for numbers
 * @s: string to calculate.
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	for (len = 0; s[len] != '\0'; len++)
	{
		if (isdigit(s[len]) == 0)
		{
			printf("Error\n");
			exit(98);
		}
	}
	return (len);
}

/**
 * main - print out the argument count.
 * @argc: argument count.
 * @argv: argument vector array.
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	int len1, len2, i, j, carry, sum, n1, n2, n1idx = 0, n2idx = 0;
	int result[100000] = {0};

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = argv[1][i] - '0';
		n2idx = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = argv[2][j] - '0';
			sum = n1 * n2 + result[n1idx + n2idx] + carry;
			carry = sum / 10;
			result[n1idx + n2idx] = sum % 10;
			n2idx++;
		}
		if (carry > 0)
			result[n1idx + n2idx] += carry;
		n1idx++;
	}
	i = 99999;
	while (i >= 0 && result[i] == 0)
		i--;
	if (i == -1)
	{
		printf("0\n");
		return (0);
	}
	for (; i >= 0; i--)
		printf("%d", result[i]);
	printf("\n");
	return (0);
}
