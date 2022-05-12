#include "monty.h"

/**
 * main - monty
 * @argc: argument count
 * @argv: argument variable
 * Return: return 0
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	const char *filename = argv[1];
	size_t bufsize = 0;
	char *buff = NULL;
	FILE *_open = fopen(filename, "r");
	char *token = NULL;
	char *tokens[1024];
	int i = 0, retorno = 0;

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
		token = strtok(buff, "\t\n");
		while (token != NULL)
		{
			tokens[i] = token;
			tokens[i + 1] = NULL;
			token = strtok(NULL, " \t\n");
			i++;
		}
	}
	free(buff);
	return (retorno);
}
