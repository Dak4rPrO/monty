#include "monty.h"

/**
 * @brief 
 * 
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    ssize_t _open, _read;
    char *buff = malloc(sizeof(char) * letters);

	if (filename == NULL || buff == NULL)
        printf("Error: malloc failed\n");
		exit (EXIT_FAILURE);

	_open = open(filename, O_RDONLY);

    if (_open == -1)
	{
        printf("Error: Can't open file %s\n", filename);
		free(buff);
		exit (EXIT_FAILURE);
	}

	_read = read(_open, buff, letters);

	free(buff);
	close(_open);

	exit (EXIT_SUCCESS);
}