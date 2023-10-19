#include "monty.h"

/**
 * custom_pop - Remove the top element from the stack.
 * @stack: A pointer to the stack.
 * @line_cnt: The current line number.
 *
 * Return: No return value.
 */
void custom_pop(stack_t **stack, unsigned int line_cnt)
{
	stack_t *top_element;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_cnt);
		fclose(bus.file);
		free(bus.content);
		_FreeStack(*stack);
		exit(EXIT_FAILURE);
	}

	top_element = *stack;
	*stack = top_element->next;
	free(top_element);
}

