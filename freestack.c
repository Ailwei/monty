#include "monty.h"

/**
 * _FreeStack - Frees a doubly linked list.
 * @list_head: Pointer to the head of the list
 */
void _FreeStack(stack_t *list_head)
{
    stack_t *current_node, *temp;

    current_node = list_head;
    while (current_node)
    {
        temp = current_node->next;
        free(current_node);
        current_node = temp;
    }
}

