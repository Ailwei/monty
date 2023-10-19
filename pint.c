#include "monty.h"

/**
 * pint_top - Print the value at the top of the stack.
 * @stack: Stack head
 * @line_cnt: Line number
 *
 * Return: No return
 */
void pint_top(stack_t **stack, unsigned int line_cnt)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_cnt);
		fclose(bus.file);
		free(bus.content);
		_FreeStack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

