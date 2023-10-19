#include "monty.h"

/**
 * _addNode - Add a new node to the top of the stack.
 * @stack: Pointer to the stack
 * @new_v: New value to add
 * Return: No return value
 */
void _addNode(stack_t **stack, int new_v)
{
    stack_t *new_node, *top;

    top = *stack;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory for the new node\n");
        exit(EXIT_FAILURE);
    }
    
    if (top)
    {
        top->prev = new_node;
    }

    new_node->n = new_v;
    new_node->next = *stack;
    new_node->prev = NULL;
    *stack = new_node;
}

