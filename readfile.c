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
	unsigned int line_number;
	const char *filename = argv[1];
	size_t bufsize = 0;
	char *buff = NULL, *tokens[1024], *token = NULL;
	FILE *_open = fopen(filename, "r");
	int i = 0;
	void (*f)(stack_t **stack, unsigned int line_number);

	printf("antes del malloc");
	buff = malloc(sizeof(char));
	printf("despues del malloc");

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
		token = strtok(buff, "\t\n ");
		
		f = get_func(token);
		f(&stack, line_number);
	}
	free(buff);
}
