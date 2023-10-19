#include "monty.h"

/**
 * rotate_right - Rotates the stack to the bottom.
 * @stack: Pointer to the stack
 * @line_cnt: Line number
 * Return: No return value
 */
void rotate_right(stack_t **stack, __attribute__((unused)) unsigned int line_cnt)
{
    stack_t *cpy;

    cpy = *stack;
    if (*stack == NULL || (*stack)->next == NULL)
    {
        return;
    }
    while (cpy->next)
    {
        cpy = cpy->next;
    }
    cpy->next = *stack;
    cpy->prev->next = NULL;
    cpy->prev = NULL;
    (*stack)->prev = cpy;
    (*stack) = cpy;
}

