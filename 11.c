#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    FILE *file;
    char *content;
    char *arg;     
} Bus;

Bus bus;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


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

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    if (*stack == NULL)
    {
        return;
    }

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void process_monty(const char *filename)
{
    unsigned int line_number = 1;
    size_t i;

    instruction_t instruct[] = {
        {"push", push},
        {"pall$", pall},
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


int main(int argc, char *agrv[])
{
    char *filename;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: %s file\n", agrv[0]);
        exit(EXIT_FAILURE);
    }

    filename = agrv[1];

    process_monty(filename);

    return (0);
}
