#include "monty.h"

/**
 * rotate_left - Rotates the stack to the top.
 * @stack: Pointer to the stack
 * @line_cnt: Line number (unused attribute)
 * Return: No return value
 */
void rotate_left(stack_t **stack,  __attribute__((unused)) unsigned int line_cnt)
{
	stack_t *current = *stack, *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	temp = (*stack)->next;
	temp->prev = NULL;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = current;
	(*stack) = temp;
}

