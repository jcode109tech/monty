#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct {
    FILE *file;
    char *content;
    char *arg;  
    int is_queue;   
} Bus;

Bus bus;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void process_monty(const char *filename);
void pint(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void multiply(stack_t **stack, unsigned int line_number);
void modulus(stack_t **stack, unsigned int line_number);
void print_char(stack_t **stack, unsigned int line_number);
void set_mode(stack_t **stack, unsigned int line_number, int is_queue);
void rotate_right(stack_t **stack, unsigned int line_number);

void rotate_left(stack_t **stack, unsigned int line_number);
void print_string(stack_t **stack, unsigned int line_number);

int custom_strmatch(char *s1, const char *s2);
void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number, instruction_t *instructions, size_t num_instructions);

#endif
