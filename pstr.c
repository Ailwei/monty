#include "monty.h"

/**
 * pstr_print - Print the string starting at the top of the stack, followed by a new line.
 * @stack: Pointer to the stack
 * @line_cnt: Line number
 * Return: No return value
 */
void pstr_print(stack_t **stack, unsigned int line_cnt)
{
	stack_t *top;
	(void)line_cnt;

	top = *stack;
	while (top)
	{
		if (top->n > 127 || top->n <= 0)
		{
			break;
		}
		printf("%c", top->n);
		top = top->next;
	}
	printf("\n");
}

