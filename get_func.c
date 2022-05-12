#include "monty.h"
#define BUFFER_SIZE 1024

/**
 * get_func - function
 * @opcode: format
 * Return: NULL
 */
void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t instruction_s[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"\0", NULL}
	};

	for (i = 0; *instruction_s[i].opcode != '\0'; i++)
	{
		if (strcmp(opcode, instruction_s[i].opcode == 0))
			return (instruction_s[i].f);
	}
	putchar(*opcode);
	return (NULL);
}
