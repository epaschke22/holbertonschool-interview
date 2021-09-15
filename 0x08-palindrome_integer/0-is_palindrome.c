#include "palindrome.h"

/**
 * is_palindrome - checks if a number is a palindrome
 * @n: input number
 * Return: 1 if true, else 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long int front = 1, back = 10;
	unsigned long int temp;

	if (n < 10)
		return (1);
	temp = n;
	while (temp > 10)
	{
		temp /= 10;
		front *= 10;
	}
	while (front >= back)
	{
		if (n / front % 10 != n % back)
			return (0);
		front /= 100;
		n /= 10;
	}
	return (1);
}
