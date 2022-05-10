#include "monty.h"

/**
 * @brief 
 * 
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	const char *filename = argv[1];
    	size_t bufsize = 0;
	char *buff = NULL;
	FILE* _open = fopen(filename, "r");

	/*char *buff = malloc(sizeof(char) * letters);

	if (buff == NULL)
	{
		printf("Error: malloc failed\n");
		exit (EXIT_FAILURE);
	}
*/	
    
	/*if (_open == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		free(buff);
		exit (EXIT_FAILURE);
	}*/

	while (getline(&buff, &bufsize, _open) != -1)
	{
		printf("%s", buff);
	}
	
	/*free(buff);*/

	return (0);
}
