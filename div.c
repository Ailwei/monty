#include "monty.h"

/**
 * div_func - Division operation.
 * @stack: Pointer to the stack.
 * @line_cnt: Line number in the Monty file.
 *
 * Return: No return value.
 */
void div_func(stack_t **stack, unsigned int line_cnt)
{
    stack_t *current;
    int division_r;
    int node_count = 0;

    current = *stack;

 
    while (current)
    {
        current = current->next;
        node_count++;
    }

    if (node_count < 2)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_cnt);
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

    division_r = current->next->n / current->n;
    current->next->n = division_r;
    *stack = current->next;
    free(current);
}

