#include "monty.h"

/**
 * push_func - Push an element onto the stack.
 * @stack: Pointer to the stack.
 * @line_cnt: Line number in the Monty file.
 *
 * Return: No return value.
 */
void push_func(stack_t **stack, unsigned int line_cnt)
{
	int v;
	char *arg = bus._argument;

	if (!arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_cnt);
		fclose(bus.file);
		free(bus.content);
		exit(EXIT_FAILURE);
	}

	
	if (!is_valid_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_cnt);
		fclose(bus.file);
		free(bus.content);
		exit(EXIT_FAILURE);
	}
	v = atoi(arg);
	_addNode(stack, v);
}
