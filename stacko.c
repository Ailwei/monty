#include "monty.h"

/**
 * stack_mode - Set the stack mode to 0.
 * @stack: Pointer to the stack (unused)
 * @line_cnt: Line number (unused)
 * Return: No return value
 */
void stack_mode(stack_t **stack, unsigned int line_cnt)
{
    (void)stack;
    (void)line_cnt;
    bus.stack_flag = 0;
}

