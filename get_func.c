#include "monty.h"
#define BUFFER_SIZE 1024

/**
 * get_func - function
 * @func: format
 * Return: contador
 */
void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t instruction_s[] = {
		{"push", push},
		{"\0", NULL}
	};

	for (i = 0; *instruction_s[i].opcode != '\0'; i++)
	{
		if (*opcode == *instruction_s[i].opcode)
			return (instruction_s[i].f);
	}
	putchar(*opcode);
}
