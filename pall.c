#include "monty.h"

/**
 * pall - Prints all the elements in the stack
 * @stack: Pointer to the head of the stack
 *
 * Description: Prints all elements of the stack starting
 * from the top of the stack.
 */

void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

