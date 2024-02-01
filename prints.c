#include "monty.h"

void print_string(stack_t **stack, unsigned int line_number)
{
    
    stack_t *current = *stack;
    (void)line_number;

    while (current != NULL && current->n != 0 && isprint(current->n)) {
        printf("%c", (char)current->n);
        current = current->next;
    }

    printf("\n");
}