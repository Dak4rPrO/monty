#include "monty.h"

/**
* push - recibe un int y lo manda al stack
* @stack: pointer to linked list stack
* @line_number: number of line opcode occurs on
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	char *tok;
	int atok = 0;


	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		Free_s(stack);
		exit(EXIT_FAILURE);
	}

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	tok = strtok(NULL, " \n\t");

	if (isNumber(tok) == 0 && tok != NULL)
		atok = atoi(tok);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	top->n = atok;
	top->next = *stack;
	top->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * pall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *dentrostack = *stack;

	if (*stack == NULL)
		return;

	while (dentrostack != NULL)
	{
		printf("%d\n", dentrostack->n);
		dentrostack = dentrostack->next;
	}
}

/**
* nop - funcion que no hace nada XD
* @stack: pointer to linked list stack
* @line_number: number of line opcode occurs on
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
* pint - imprime el valor en la parte superior de la pila
* @stack: pointer to linked list stack
* @line_number: number of line opcode occurs on
*/
void pint(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	if (*stack == NULL)
		exit(EXIT_FAILURE);

	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *temp = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	temp = current;

	if (current->next)
	{
		current = current->next;
		current->prev = temp->prev;
		*stack = current;
	}
	else
		*stack = NULL;
	free(temp);
}
