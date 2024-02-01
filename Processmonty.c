#include "monty.h"

void process_monty(const char *filename)
{
    unsigned int line_number = 1;
    size_t i;

    instruction_t instruct[] = {
    {"push", push},
    {"pall$", pall},
    {"pall", pall},
    {"pint", pint},
    {"swap", swap},
    {"nop", nop},
    {"add", add}, 
};


    stack_t *stack = NULL;
    bus.file = fopen(filename, "r");
    bus.content = malloc(1024);
    bus.arg = NULL;

    if (bus.file == NULL || bus.content == NULL)
    {
        fprintf(stderr, "Error: Memory allocation or file open failed\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(bus.file, "%s", bus.content) != EOF)
    {
        int found_opcode = 0;

        for (i = 0; i < sizeof(instruct) / sizeof(instruct[0]); i++)
        {
            if (strcmp(bus.content, instruct[i].opcode) == 0)
            {
                instruct[i].f(&stack, line_number);
                found_opcode = 1;
                break;
            }
        }

        if (!found_opcode)
        {
            fprintf(stderr, "L%d: unknown opcode %s\n", line_number, bus.content);
            exit(EXIT_FAILURE);
        }

        line_number++;
    }

    fclose(bus.file);
    free(bus.content);
}


