#include "monty.h"
#define BUFFER_SIZE 1024

/**
 * _count - Count the characters
 * @list: list
 * Return: Number of characters
 */
int _count(stack_t list)
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
int (*get_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t instruction_s[] = {
		{"push", push},
		{"\0", NULL}
	};

	for (i = 0; *instruction_s[i].opcode != '\0'; i++)
	{
		if (opcode == *instruction_s[i].opcode)
		{
			return (instruction_s[i].f);
		}
	}
	putchar('%');
	putchar(opcode);
	return (_count);
}
