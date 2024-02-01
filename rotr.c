#include "monty.h"

void rotate_right(stack_t **stack, unsigned int line_number) 
{
    stack_t *last = *stack;
    (void)line_number;
    
    if (*stack != NULL && (*stack)->next != NULL)
    {
        last = *stack;
        while (last->next != NULL) 
            last = last->next;
        
        last->next = *stack;
        *stack = (*stack)->next;
        last->next->next = NULL;
    }
}