#include "monty.h"

void divide(stack_t **stack, unsigned int line_number) 
{
    int result = 0;
    stack_t *temp; 

    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0) {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    result = (*stack)->next->n / (*stack)->n;
    
    temp = *stack;
    *stack = (*stack)->next;
    free(temp);

    (*stack)->n = result;
}