#include "monty.h"

void process_monty(const char *filename)
{
    unsigned int line_number = 1;
    stack_t *stack = NULL;
    size_t i;
    int found_opcode;

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
    {"pchar", print_char},
};


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
        if (bus.content[0] == '#') 
            continue;
        
        found_opcode = 0;

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

}

    /* while (fscanf(bus.file, "%s", bus.content) != EOF) {
        char *token = strtok(bus.content, " \t\n$");

        while (token != NULL) {

            execute_instruction(token, instruct, sizeof(instruct) / sizeof(instruct[0]));

            
            token = strtok(NULL, " \t\n$");
        }
    }

    fclose(bus.file);
    free(bus.content);
}

void execute_instruction(const char *instruction, instruction_t *instructions, size_t num_instructions) {
    unsigned int line_number = 1;
    stack_t *stack = NULL;
    size_t i;
    for (i = 0; i < num_instructions; i++) {
        if (strcmp(instruction, instructions[i].opcode) == 0) {
            instructions[i].f(&stack, line_number);
            return; 
        }
    }
    
    printf("Error: Unknown instruction '%s'\n", instruction);
}
*/