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
	int len1, len2, i, j, tmp;
	int arg1[100], arg2[100];
	int result[200] = {0};

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);
	if (atoi(argv[1]) == 0 || atoi(argv[2]) == 0)
	{
		printf("0\n");
		return (0);
	}
	for (i = len1 - 1, j = 0; i >= 0; i--, j++)
	{
		arg1[j] = argv[1][i] - '0';
	}
	for (i = len2 - 1, j = 0; i >= 0; i--, j++)
	{
		arg2[j] = argv[2][j] - '0';
	}
	for (i = 0; i < len2; i++)
		for (j = 0; j < len1; j++)
			result[i + j] += arg1[i] * arg2[j];
	for (i = 0; i < len1 + len2; i++)
	{
		tmp = result[i] / 10;
		result[i] = result[i] % 10;
		result[i + 1] = result[i + 1] + tmp;
	}
	for (i = len1 + len2; i >= 0; i--)
		if (result[i] > 0)
			break;
	for (; i >= 0; i--)
		printf("%d", result[i]);
	printf("\n");
	return (0);
}
