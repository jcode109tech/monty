#include "monty.h"

void rotate_left(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    if (*stack != NULL && (*stack)->next != NULL) {
        int temp = (*stack)->n;
        stack_t *current = *stack;

        while (current->next != NULL) {
            current->n = current->next->n;
            current = current->next;
        }

        current->n = temp;
    }
}