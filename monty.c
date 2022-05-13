#include "monty.h"
/**
 * main - monty
 * @argc: argument count
 * @argv: argument variable
 * Return: return 0
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	const char *filename = argv[1];
	size_t bufsize = 0;
	char *buff = NULL, *token = NULL;
	FILE *_open = fopen(filename, "r");
	void (*f)(stack_t **stack, unsigned int line_number);

	if (argc > 2 || filename == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);	}
	if (_open == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free(buff), exit(EXIT_FAILURE);	}
	while (getline(&buff, &bufsize, _open) != -1)
	{
		line_number++;
		token = strtok(buff, "\t\n ");
		if (token == NULL || token[0] == '#')
			continue;

		f = get_func(token);
		if (f == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			free(buff), fclose(_open), exit(EXIT_FAILURE);	}
		f(&stack, line_number);
		free(buff);	
		buff = NULL;	}
	free(buff), fclose(_open), Free_s(&stack);
	return (0);
}
