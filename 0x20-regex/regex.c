#include "regex.h"


/**
 * regex_match - checks if a string matches a regex pattern
 * @str: string to compare
 * @pattern: pattern to compare
 * Return: 1 if true, else 0
 */
int regex_match(char const *str, char const *pattern)
{
	if (*str == 0 && *pattern == 0)
		return (1);
	if (*str == *pattern || *pattern == '.')
		return (regex_match(str + 1, pattern + 1));
	if (*pattern == '*')
	{
		if (*str == 0)
			return (regex_match(str, pattern + 1));
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 1));
	}
	return (0);
}
