#include "monty.h"

/**
*
*
*/
void push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = atoi(strtok(NULL, " "));
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * @brief 
 * 
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;
	(void) line_number;

	while (p != NULL)
	{
		fprintf(stderr, "%d\n", p->n);
		p = p->next;
	}
}
