#include "monty.h"


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

