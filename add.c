#include "monty.h"

/**
 * add_func - Adds the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_cnt: Line number in the Monty file.
 *
 * Return: No return value.
 */
void add_func(stack_t **stack, unsigned int line_cnt)
{
    stack_t *current;
    int stack_length = 0;
    int r;

    current = *stack;

   
    while (current)
    {
        current = current->next;
        stack_length++;
    }

    if (stack_length < 2)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_cnt);
        fclose(bus.file);
        free(bus.content);
        _FreeStack(*stack);
        exit(EXIT_FAILURE);
    }

    
    current = *stack;
    r = current->n + current->next->n;
    current->next->n = r;
    *stack = current->next;
    free(current);
}

