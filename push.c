#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the head of the stack
 * @value: Value to be pushed onto the stack
 * @line_number: Line number of the opcode in the file
 *
 * Description: Creates a new node with the given value and
 * pushes it onto the top of the stack.
 */

void push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;
	
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

