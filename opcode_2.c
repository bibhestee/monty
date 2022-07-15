#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: current line number
 * Description: swaps if stack is geater than 2
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;
	stack_t *current = *stack;
	if (TOO_SHORT)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp = current->n;
		current->n = current->next->n;
		current->next->n = tmp;
	}
}


/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: current line number
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed, so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter.
 *
 */

void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *current = *stack;
	if (TOO_SHORT)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		sum = current->n + current->next->n;
		current = current->next;
		free(*stack);
		current->n = sum;
		*stack = current;
	}
	stack_len--;
}


/**
 * free_all - frees all the allocated memory
 * @stack: pointer to the top of the stack;
 * Description: all allocated memories must be freed after usage.
 *
 */

void free_all(stack_t **stack)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		return;
	}

	while (!temp)
	{
		temp = temp->next;
		free(*stack);
		*stack = temp;
	}
}
