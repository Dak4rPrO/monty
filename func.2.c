#include "monty.h"

/**
* swap - intercambia los dos elementos superiores de la pila
* @stack: pointer to linked list stack
* @line_number: number of line opcode occurs on
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *curr = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	while (curr->next != NULL)
		curr = curr->next;

	temp = curr->n;
	curr->n = curr->prev->n;
	curr->prev->n = temp;
}

/**
* add - añade los dos elementos superiores de la pila
* @stack: pointer to linked list stack
* @line_number: number of line opcode occurs on
*/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	if (stack == NULL || (*stack) == NULL || (*stack)->next == NULL || *stack)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(curr);
}
