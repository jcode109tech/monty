#include "monty.h"

void process_monty(const char *filename)
{
    unsigned int line_number = 1;
    stack_t *stack = NULL;

    instruction_t instruct[] = {
        {"push", push},
        {"pall$", pall},
        {"pall", pall},
        {"pint", pint},
        {"swap", swap},
        {"nop", nop},
        {"add", add},
        {"sub", sub},
        {"div", divide},
        {"mul", multiply},
        {"mod", modulus},
        {"rotl", rotate_left},
        {"rotr", rotate_right},  
         
    };

    bus.file = fopen(filename, "r");
    bus.content = malloc(sizeof
    (bus.file));


    if (bus.file == NULL || bus.content == NULL)
    {
        fprintf(stderr, "Error: Memory allocation or file open failed\n");
        exit(EXIT_FAILURE);
    }


    while (fscanf(bus.file, "%s", bus.content) != EOF)
    {
        /*op = strtok(bus.content, " \n\t");*/
        if (bus.content[0] == '#') 
            continue;

        /*ustom_strmatch(op, "$");

        bus.arg = strtok(NULL, " \n\t");*/

        execute_instruction(bus.content, &stack, line_number, instruct, sizeof(instruct) / sizeof(instruct[0]));

        line_number++;
    }

}

  