#include "slide_line.h"

/**
 * slide_left - slides a row of numbers like 2048 to the left
 * @line: input row of numbers
 * @size: the number of items in the row
 * Return: 1 if success, else 0
 */
int slide_left(int *line, size_t size)
{
	int n = 0, i, _i, temp;

	for (i = 0; i < (int)size; i++)
		if (line[i] > 0)
		{
			if (n != 0 && line[i] == n)
			{
				line[i] += n;
				line[_i] = 0;
				n = 0;
			}
			else
			{
				_i = i;
				n = line[i];
			}
		}
	_i = 0;
	for (i = 0; i < (int)size; i++)
	{
		if (line[i] > 0)
		{
			temp = line[_i];
			line[_i] = line[i];
			line[i] = temp;
			_i++;
		}
	}
	return (1);
}

/**
 * slide_right - slides a row of numbers like 2048 to the left
 * @line: input row of numbers
 * @size: the number of items in the row
 * Return: 1 if success, else 0
 */
int slide_right(int *line, size_t size)
{
	int n = 0, i, _i, temp;

	for (i = (int)size - 1; i >= 0; i--)
		if (line[i] > 0)
		{
			if (n != 0 && line[i] == n)
			{
				line[i] += n;
				line[_i] = 0;
				n = 0;
			}
			else
			{
				_i = i;
				n = line[i];
			}
		}
	_i = (int)size - 1;
	for (i = (int)size - 1; i >= 0; i--)
	{
		if (line[i] > 0)
		{
			temp = line[_i];
			line[_i] = line[i];
			line[i] = temp;
			_i--;
		}
	}
	return (1);
}

/**
 * slide_line - slides a row of numbers like 2048
 * @line: input row of numbers
 * @size: the number of items in the row
 * @direction: direction to push all numbers
 * Return: 1 if success, else 0
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == 0)
		return(slide_left(line, size));
	return (slide_right(line, size));
}
