#include "monty.h"

/**
 * set_queue_mode - Set the queue mode to 1.
 * @stack: Pointer to the stack (unused)
 * @line_cnt: Line number (unused)
 * Return: No return value
 */
void set_queue_mode(stack_t **stack, unsigned int line_cnt)
{
    (void)stack;
    (void)line_cnt;
    bus.stack_flag = 0;
}

/**
 * enqueue - Add a node to the tail of the stack.
 * @stack: Pointer to the stack
 * @new_v: New value to add
 * Return: No return value
 */
void add_Queue(stack_t **stack, unsigned int new_v)
{
    stack_t *new_node, *tail;

    tail = *stack;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory for new node\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = new_v;
    new_node->next = NULL;

    if (tail)
    {
        while (tail->next)
            tail = tail->next;
    }

    if (!tail)
    {
        *stack = new_node;
        new_node->prev = NULL;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
    }
}

