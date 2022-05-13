#include "monty.h"

/**
* Free_s - libera stack y sus nodos
* @stack: puntero al puntero de head de stack
*/

void Free_s(stack_t **stack)
{
	stack_t *temp = NULL;

	if (*stack == NULL)
		return;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
