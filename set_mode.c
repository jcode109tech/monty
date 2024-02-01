#include "monty.h"


void set_mode(stack_t **stack, unsigned int line_number, int is_queue) 
{
    bus.is_queue = is_queue;
    (void)stack;
    (void)line_number;
}