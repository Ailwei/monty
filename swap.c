#include "monty.h"

/**
 * swap_func - Swap the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_cnt: Line number in the Monty file.
 *
 * Return: No return value.
 */
void swap_func(stack_t **stack, unsigned int line_cnt)
{
    stack_t *current;
    int stack_length = 0;
    int temp;

    current = *stack;

    
    while (current)
    {
        current = current->next;
        stack_length++;
    }

    if (stack_length < 2)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_cnt);
        fclose(bus.file);
        free(bus.content);
        _FreeStack(*stack);
        exit(EXIT_FAILURE);
    }

    
    current = *stack;
    temp = current->n;
    current->n = current->next->n;
    current->next->n = temp;
}

