#include "monty.h"

/**
 * isNumber - checkea si el token es un numero o no
 * @string: token dado
 * Return: 0 es bien, 1 es mal
*/
int isNumber(char *string)
{
	unsigned int index = 0;

	if (string == NULL)
		return (1);

	if (string[0] == '-')
		index++;

	while (string[index])
	{
		if (string[index] >= 48 && string[index] <= 57)
		{
			index++;
			continue;
		}
		return (1);
	}
	return (0);
}
