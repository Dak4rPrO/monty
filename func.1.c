#include "monty.h"

/**
*
*
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = atoi(strtok(NULL, " "));
	top->next = *stack;
	top->prev = NULL;

	if (top->n < 48 || top->n > 57)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * _pall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{	
	stack_t *dentrostack;

	dentrostack = *stack;

	if (dentrostack == NULL)
		return;
	while (dentrostack != NULL)
	{
		printf("%d\n", dentrostack->n);
		dentrostack = dentrostack->next;
	}
}
