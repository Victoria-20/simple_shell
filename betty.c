#include "main.h"

/**
* main - check for betty coding style
* @argc: argument count
* @argv: arguments passed
* Return: Always 0 if successful
*/

int main(int argc, char *argv[])
{
	int i = 0;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
