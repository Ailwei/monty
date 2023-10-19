#include "monty.h"

/**
 * mod_func - Computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: Pointer to the stack.
 * @line_cnt: Line number in the Monty file.
 * Return: No return value.
 */
void mod_func(stack_t **stack, unsigned int line_cnt)
{
    stack_t *current;
    int remainder;
    int node_count = 0;

    current = *stack;

    
    while (current)
    {
        current = current->next;
        node_count++;
    }

    if (node_count < 2)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_cnt);
        fclose(bus.file);
        free(bus.content);
        _FreeStack(*stack);
        exit(EXIT_FAILURE);
    }

    current = *stack;

    if (current->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_cnt);
        fclose(bus.file);
        free(bus.content);
        _FreeStack(*stack);
        exit(EXIT_FAILURE);
    }

    remainder = current->next->n % current->n;
    current->next->n = remainder;
    *stack = current->next;
    free(current);
}

