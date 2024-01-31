#include "monty.h"


void push(stack_t **stack, unsigned int line_number)
{
    int value;
    stack_t *new_node = NULL;
     
    if (fscanf(bus.file, "%s", bus.content) != 1 || !isdigit(bus.content[0]))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(bus.file);
        free(bus.content);
        exit(EXIT_FAILURE);
    }

    value = atoi(bus.content);

    new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        fclose(bus.file);
        free(bus.content);
        
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
    {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

