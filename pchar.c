#include "monty.h"


void print_char(stack_t **stack, unsigned int line_number)
{
    int ascii_value;
    
    if (*stack == NULL) {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    ascii_value = (*stack)->n;

    if (!isprint(ascii_value)) {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", (char)ascii_value);
}