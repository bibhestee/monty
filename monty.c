#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 *
 */

int main(int argc, char** argv)
{
	FILE *fp;
	char *str = malloc(sizeof(char) *10);
	size_t l = 0;
	char* s;

	if (argc != 2)
	{
		printf("Wrong usage\n");
		return (-1);
	}
	s = argv[1];

	fp = fopen(s, "r");

	if (!fp)
	{
		printf("File not open!\n");
	}

	while (getline(&str, &l, fp) > 0)
	{

		puts(str);
		l++;
	}

	fclose(fp);
}
