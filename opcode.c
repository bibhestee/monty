#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * push - push new node to top of the stack
 * @top: pointer to the top of the stack
 * @n: data of the new node
 * Description: A new node is added to the top
of the stack either when empty or not.
 * Return: EXIT_SUCCESS or Error is failed
 */

char *push(stack_t **top, int n)
{
	stack_t *temp = *top;

	/* Create a new stack node */
	stack_t *node = malloc(sizeof(stack_t));

	/* Check if memory is allocated successfully */
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		printf("EXIT_FAILURE");
	}

	/* Initialize the new stack node */
	node->n = n;
	node->prev = NULL;
	node->next = NULL;

	if (*top == NULL) /* if top is empty */
	{
		/* Add new stack node to the top */
		*top = node;
	}
	else
	{
		node->next = temp;
		temp->prev = node;
		*top = node;
	}
	return (EXIT_SUCCESS);
}


/**
 * pop - pop the top node from the stack
 * @top: pointer to the top of the stack
 * Description: The top of the stack is removed if
stack is not empty.
 * Return: EXIT_SUCCESS or
Error if stack is empty.
 */


char *pop(stack_t **top)
{
	stack_t *temp = *top;

	/* Check if stack is empty */
	if (*top == NULL)
	{
		printf("L<line_number>: can't pop an empty stack\n");
		printf("EXIT_FAILURE");
	}
	else
	{
		/* Move top to the next node */
		temp = temp->next;
		free(*top);
		*top = temp;
	}
	return (EXIT_SUCCESS);
}


/**
 * pall - prints all the values on the stack,
starting from the top of the stack.
 * @top: pointer to the top of the stack
 * Description: prints all values followed by a new line
 *
 */

void pall(stack_t **top)
{
	stack_t *current = *top;

	/* If stack is not empty */
	if (*top != NULL)
	{
		while (current != NULL)
		{
			printf("%i\n", current->n);
			current = current->next;
		}
	}
}


/**
 * pint - prints the value at the top of the stack,
 followed by a new line
 * @top: pointer to the top of the stack
 *
 */

void pint(stack_t **top)
{
	stack_t *current = *top;
	/* Error if empty */
	if (*top == NULL)
	{
		printf("L<line_number>: can't pint, stack empty\n");
		printf("EXIT_FAILURE");
	}
	else
	{
		printf("%i\n", current->n);
	}
}
