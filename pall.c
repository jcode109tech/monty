#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    if (stack == NULL || *stack == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

