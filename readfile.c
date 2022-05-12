#include "monty.h"

/**
 * main - monty
 * @argc: argument count
 * @argv: argument variable
 * Return: return 0
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line_number = 1;
	const char *filename = argv[1];
	size_t bufsize = 0;
	char *buff = NULL, *token = NULL;
	FILE *_open = fopen(filename, "r");
	void (*f)(stack_t **stack, unsigned int line_number);

	buff = malloc(sizeof(char));

	if (buff == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (_open == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free(buff);
		exit(EXIT_FAILURE);
	}

	while (getline(&buff, &bufsize, _open) != -1)
	{
		line_number++;
		token = strtok(buff, "\t\n ");
		
		f = get_func(token);
		f(&stack, line_number);
	}
	free(buff);
	return (0);
}
