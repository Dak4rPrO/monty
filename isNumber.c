#include "monty.h"

/**
 * _isdigit - check the code
 * @c : l
 * Return: Always 0.
*/
int isNumber(char *c)
{
	unsigned int index = 0;

	if (c == NULL)
		return (1);

	if (c[0] == '-')
		index++;

	while (c[index])
	{
		if (c[index] >= 48 && c[index] <= 57)
		{
			index++;
			continue;
		}
		return (1);
	}
	return (0);
}
