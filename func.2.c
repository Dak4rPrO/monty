#include "monty.h"

/**
* swap - intercambia los dos elementos superiores de la pila
* @stack: pointer to linked list stack
* @line_number: number of line opcode occurs on
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *curr, *prev = NULL;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	for (curr = *stack; curr->next != NULL; curr = curr->next)
		prev = curr;

	temp = curr->n;
	curr->n = prev->n;
	prev->n = temp;
}
