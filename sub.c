#include "monty.h"

/**
 * sub_func - Subtraction operation.
 * @stack: Pointer to the stack.
 * @line_cnt: Line number in the Monty file.
 *
 * Return: No return value.
 */
void sub_func(stack_t **stack, unsigned int line_cnt)
{
    stack_t *current;
    int subtraction_answer;
    int node_count = 0;

    current = *stack;

   
    while (current)
    {
        current = current->next;
        node_count++;
    }

    if (node_count < 2)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_cnt);
        fclose(bus.file);
        free(bus.content);
        _FreeStack(*stack);
        exit(EXIT_FAILURE);
    }

    current = *stack;
    subtraction_answer = current->next->n - current->n;
    current->next->n = subtraction_answer;
    *stack = current->next;
    free(current);
}

