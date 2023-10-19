#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - represent stack
 * @dt : integer
 * @prevNode: point to the previous element of stack
 * @nextNode: points to th next element
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
}stack_t;

/**
 * struct bus_s - variables - args, file, line content
 * @argument_vector: value
 * @file - ponter to monty file
 * @content - line content
 * stack_flag: flag change stack
 */


typedef struct bus_s
{
	char *_argument;
	FILE *file;
	char *content;
	int stack_flag;
}custom_bus_t;

extern custom_bus_t bus;


/**
 * struct instr_s - opcode and its funct
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 */

 typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
}instruction_t;

void push_func(stack_t **head, unsigned int line_cnt);
void add_Queue(stack_t **head, unsigned int new_v);
void _addNode(stack_t **head, int new_v);
void _FreeStack(stack_t *list_head);
void pall_funct(stack_t **head, unsigned int cnt);
void pint_top(stack_t **stack, unsigned int line_cnt);
void custom_pop(stack_t **stack, unsigned int line_cnt);
int is_valid_integer(const char *str);
void swap_func(stack_t **stack, unsigned int line_cnt);
void add_func(stack_t **stack, unsigned int line_cnt);
void nop_func(stack_t **stack, unsigned int h);
void sub_func(stack_t **stack, unsigned int line_cnt);
void div_func(stack_t **stack, unsigned int line_cnt);
void mul_func(stack_t **stack, unsigned int line_cnt);
void mod_func(stack_t **stack, unsigned int line_cnt);
void pchar_handler(stack_t **stack, unsigned int line_cnt);
void pstr_print(stack_t **stack, unsigned int line_cnt);
void rotate_left(stack_t **stack,  __attribute__((unused)) unsigned int line_cnt);
void rotate_right(stack_t **stack, __attribute__((unused)) unsigned int line_cnt);
int exec_opcode(char *line_cont, stack_t **stack_head, unsigned int line_cnt, FILE *monty_file);
void custom_pop(stack_t **stack, unsigned int line_cnt);
void swap_func(stack_t **stack, unsigned int line_cnt);
void stack_mode(stack_t **stack, unsigned int line_cnt);

#endif
