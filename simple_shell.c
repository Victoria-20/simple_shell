#include "main.h"

/**
 * main - program that runs a simple UNIX command line interpreter
 * The prompt is displayed again each time a command has been executed
 * we will use execve(), fork() and wait() functions
 * @argc: number of arguments passed
 * @argv: string of arguments passed
 *
 * Return: Always 0.
 */

int main(void)
{

	char *args[] = {NULL, NULL};
	char *command = NULL;
	ssize_t n_bytes = 0;
	size_t len = 0;

	while (1)
	{
		printf("Enter command.\n");
		n_bytes = getline(&command, &len, stdin);
		command[n_bytes - 1] = '\0';
		args[0] = command;
		if (fork() == 0)
		{
			execve(args[0], args, NULL);
			dprintf(STDERR_FILENO, "Error %s: command not found.\n", args[0]);
			exit(0);
		}
		wait(NULL);
	}
	return (0);
}
