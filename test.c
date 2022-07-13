#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	stack_t *head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 5);
	push(&head, 7);
	push(&head, 15);
	push(&head, 9);
	pall(&head);
	printf("----\n");
	pop(&head);
	pall(&head);
	printf("-----\n");
	pint(&head);
	printf("-----\n");
	swap(&head);
	pall(&head);
	printf("------\n");
	add(&head);
	pall(&head);
	return (EXIT_SUCCESS);
}
