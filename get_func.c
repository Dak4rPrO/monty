#include "monty.h"
#define BUFFER_SIZE 1024

/**
 * _count - Count the characters
 * @list: list
 * Return: Number of characters
 */
int _count(va_list list)
{
	int count = 0;
	(void)list;

	count++;
	count++;

	return (count);
}

/**
 * get_func - function
 * @func: format
 * Return: contador
 */
int (*get_func(char func))(va_list list)
{
	int i = 0;

	instruction_t instruction_s[] = {
		{"push", push},
		{"pall", _pall},
		{"\0", NULL}
	};

	for (i = 0; *instruction_s[i].func != '\0'; i++)
	{
		if (func == *instruction_s[i].func)
		{
			return (instruction_s[i].f);
		}
	}
	putchar('%');
	putchar(func);
	return (_count);
}
