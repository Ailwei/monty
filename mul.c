#include "monty.h"

/**
 * mul_func - Multiplies the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_cnt: Line number in the Monty file.
 *
 * Return: No return value.
 */
void mul_func(stack_t **stack, unsigned int line_cnt)
{
    stack_t *current;
    int mul_result;
    int node_count = 0;

    current = *stack;

    
    while (current)
    {
        current = current->next;
        node_count++;
    }

    if (node_count < 2)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_cnt);
        fclose(bus.file);
        free(bus.content);
        _FreeStack(*stack);
        exit(EXIT_FAILURE);
    }

    current = *stack;

    mul_result = current->next->n * current->n;
    current->next->n = mul_result;
    *stack = current->next;
    free(current);
}

