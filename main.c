#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * handle_push - Handles the 'push' opcode
 * @file: File pointer to the Monty bytecode file
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 *
 * Description: Handles the 'push' opcode by reading the integer value from
 * the file and pushing it onto the stack.
 */

void handle_push(FILE *file, stack_t **stack, unsigned int line_number)
{
	int value;

	if (fscanf(file, "%d", &value) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	push(stack, value, line_number);
}

/**
 * execute_opcodes - Reads and executes Monty opcodes from a file
 * @file: File pointer to the Monty bytecode file
 * @stack: Double pointer to the head of the stack
 *
 * Description: Reads each line of the file, parses opcodes, and executes
 * the corresponding function. Handles various opcodes to manipulate a stack.
 */

void execute_opcodes(FILE *file, stack_t **stack)
{
	char opcode[100];
	unsigned int line_number = 1;

	while (fscanf(file, "%s", opcode) == 1)
	{
		if (strcmp(opcode, "push") == 0)
		{
			handle_push(file, stack, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(stack);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(stack, line_number);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(stack, line_number);
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(stack, line_number);
		}
		else if (strcmp(opcode, "add") == 0)
		{
			add(stack, line_number);
		}
		else if (strcmp(opcode, "nop") == 0)
		{
			nop(stack, line_number);
		}
		line_number++;
	}
}

/**
 * main - Entry point for the Monty bytecode interpreter
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments passed to the program
 *
 * Description: The main function reads a Monty bytecode file,
 * parses each line, and executes the corresponding opcode.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	execute_opcodes(file, &stack);

	fclose(file);
	return (EXIT_SUCCESS);
}

