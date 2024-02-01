#include "monty.h"

void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number, instruction_t *instruct, size_t num_instructions) {
    size_t i;
    char *op;
    int found_opcode = 0;

    op = strtok(opcode, " \n\t");

    /*custom_strmatch(op, "$");*/

    bus.arg = strtok(NULL, " \n\t");


    for (i = 0; i < num_instructions; i++) 
    { 
        if (strcmp(op, instruct[i].opcode) == 0) 
        {
            instruct[i].f(stack, line_number);
            found_opcode = 1;
            return;
        } 
       /* else if (custom_strmatch(opcode, instruct[i].opcode) == 0)
        {
            /printf("Function names match: %s\n", opcode);
            instruct[i].f(stack, line_number);
            found_opcode = 1;
            return; 
        }*/
    }

    if (!found_opcode)
    {
            fprintf(stderr, "L%d: unknown opcode %s\n", line_number, bus.content);
            exit(EXIT_FAILURE);
            
            
            /*
            if (custom_strmatch(opcode, instruct[i].opcode) == 0)
            {
                printf("Function names match: %s\n", opcode);
                instruct[i].f(stack, line_number);
                found_opcode = 1;
                return; 
            }
            */
            
    }
}
