#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * swap - swaps the top two elements of the stack.
 * @top: pointer to the top of the stack
 * Description: swaps if stack is geater than 2
 */

void swap(stack_t **top)
{
	int tmp;
	stack_t *current = *top;
	if (current->next == NULL)
	{
		printf("L<line_number>: can't swap, stack too short\n");
		printf("EXIT_FAILURE");
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
 * @top: pointer to the top of the stack
 * Description: The result is stored in the second top element of the stack, 
 * and the top element is removed, so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter.
 *
 */

void add(stack_t **top)
{
	int sum;
	stack_t *current = *top;
	if (current->next == NULL)
	{
		printf("L<line_number>: can't add, stack too short\n");
		printf("EXIT_FAILURE");
	}
	else
	{
		sum = current->n + current->next->n;
		current = current->next;
		free(*top);
		current->n = sum;
		*top = current;
	}
}
