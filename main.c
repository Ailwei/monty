#define  _GNU_SOURCE
#include "monty.h"

/**
 * main - Monty code interpreter
 * @arg_cmd: Number of command-line arguments
 * @arg_vect: Command-line arguments, including the Monty file location
 * Return: 0 on success
 */

custom_bus_t bus = {NULL, NULL, NULL, 0};

int main(int arg_cmd, char *arg_vect[])
{
    char *content;
    FILE *file;
    size_t scope = 0;
    ssize_t rd = 1;
    stack_t *stack = NULL;
    unsigned int cnt = 0;

    if (arg_cmd != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(arg_vect[1], "r");
    bus.file = file;

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", arg_vect[1]);
        exit(EXIT_FAILURE);
    }

    while (rd > 0)
    {
        content = NULL;
        rd = getline(&content, &scope, file);
        bus.content = content;
        cnt++;

        if (rd > 0)
        {
            exec_opcode(content, &stack, cnt, file);
        }

        free(content);
    }

    _FreeStack(stack);
    fclose(file);

    return (0);
}

