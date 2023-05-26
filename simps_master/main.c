#include "main.h"

/**
 * main - Entry Point
 * @argc: number of arguments received
 * @argv: arguments received
 * Return: 0
 **/

int main(int argc, char **argv)
{
	general_t *info;
	short status_codej;

	info = malloc(sizeof(general_t));
	if (info == NULL)
	{
		perror(argv[0]);
		exit(1);
	}

	info->pid = getpid();
	info->status_code = 0;
	info->n_commands = 0;
	info->argc = argc;
	info->argv = argv;
	info->mode = isatty(STDIN) == INTERACTIVE;
	start(info);

	status_codej = info->status_codej;

	free(info);

	return (status_codej);
}
