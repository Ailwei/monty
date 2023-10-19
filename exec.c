#include "monty.h"

/**
 * exec_opcode - Executes the opcode.
 * @line_cont: Line content
 * @stack_head: Pointer to the head of the stack
 * @line_number: Line number
 * @monty_file: Pointer to the monty file
 * Return: 0 on success, 1 on error
 */
int exec_opcode(char *line_cont, stack_t **stack_head, unsigned int line_cnt, FILE *monty_file)
{

    instruction_t opcode_table[] = {
        {"push", push_func}, {"pall", pall_funct}, {"pint", pint_top},
        {"pop", custom_pop},
        {"swap", swap_func},
        {"add", add_func},
        {"nop", nop_func},
        {"sub", sub_func},
        {"div", div_func},
        {"mul", mul_func},
        {"mod", mod_func},
        {"pchar", pchar_handler},
        {"pstr", pstr_print},
        {"rotl", rotate_left},
        {"rotr", rotate_right},
        {"queue", add_Queue},
        {"stack", stack_mode},
        {NULL, NULL}
    };

    unsigned int j = 0;
    char *operation;

    operation = strtok(line_cont, " \n\t");
    if (operation && operation[0] == '#')
        return 0;

    bus._argument = strtok(NULL, " \n\t");

    while (opcode_table[j].opcode && operation)
    {
        if (strcmp(operation, opcode_table[j].opcode) == 0)
        {
            opcode_table[j].f(stack_head, line_cnt);
            return 0;
        }
        j++;
    }

    if (operation && opcode_table[j].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_cnt, operation);
        fclose(monty_file);
        free(line_cont);
        _FreeStack(*stack_head);
        exit(EXIT_FAILURE);
    }

    return 1;
}

