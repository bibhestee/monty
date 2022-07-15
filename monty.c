#include "monty.h"

/**
 * main - main function to control all operations
 * @argc - argument counts
 * @argv - argument vector
 *
 * Return: 0 if success
 */

int main(int argc, char** argv)
{
	FILE *file;
	char *buff;
	char *opcode;
	stack_t *stack = NULL;
	size_t n;

	unsigned int line_number = 0;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buff, &n, file) > 0)
	{
		line_number++;
		opcode = strtok(buff, "\n\t\r ");
		if (opcode != NULL && opcode[0] != '#')
		{
			get_func(opcode, &stack, line_number);
		}
	}
	free_all(&stack);

	fclose(file);

	return (0);
}
