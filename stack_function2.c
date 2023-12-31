#include "monty.h"

/**
 * nop - Does nothing
 * @stack: Pointer to a pointer pointing to top node of the stack
 * @line_number: Int representing the line number of the opcode
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_nodes - Swaps the top two elements of the stack
 * @stack: Pointer to a pointer pointing to top node of the stack
 * @line_number: Interger representing the line number of of the opcode
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * nodes_add - Adds the top two elements of the stack
 * @stack: Pointer to a pointer pointing to top node of the stack
 * @line_number: Int representing the line number of of the opcode
 */
void nodes_add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nodes_sub - subtracts the top element of the stack from the second 
 * 		top element of the stack
 * @stack: Pointer to a pointer pointing to top node of the stack
 * @line_number: Int representing the line number of of the opcode
 */
void nodes_sub(stack_t **stack, unsigned int line_number)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nodes_div -  divides the second top element of the stack by the
 * 		 top element of the stack
 * @stack: Pointer to a pointer pointing to top node of the stack
 * @line_number: Interger representing the line number of of the opcode.
 */
void nodes_div(stack_t **stack, unsigned int line_number)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
