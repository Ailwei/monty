#include "monty.h"

/**
 * pall_funct - prints all values on the stack
 * @head: stack head
 * @cnt: unused line number
 *
 * Return: No return
 */
void pall_funct(stack_t **head, unsigned int cnt)
{
	stack_t *current;

	(void)cnt;

	current = *head;
	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

