#include "monty.h"

/**
 * pchar_handler - Print the character at the top of the stack, followed by a new line.
 * @stack: Pointer to the stack
 * @line_cnt: Line number
 */
void pchar_handler(stack_t **stack, unsigned int line_cnt)
{
	stack_t *top = *stack;

	if (!top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_cnt);
		fclose(bus.file);
		free(bus.content);
		_FreeStack(*stack);
		exit(EXIT_FAILURE);
	}
	if (top->n > 127 || top->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_cnt);
		fclose(bus.file);
		free(bus.content);
		_FreeStack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n);
}

