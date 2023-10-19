#include "monty.h"

/**
 * is_valid_integer - Check if a string is a valid integer.
 * @str: The string to check.
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int is_valid_integer(const char *str)
{
    if (!str || !*str)
        return 0;

    if (*str == '-' || *str == '+')
        str++; 

    for (; *str; str++)
    {
        if (!isdigit(*str))
            return 0; 
    }

    return 1; 
}

