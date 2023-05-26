#include "main.h"

/**
 * prompt - Print the prompt
 *
 * @info: Struct of general information
 **/
void prompt(general_t *info)
{
	if (info->mode == NON_INTERACTIVE)
		return;

	print("$ ");
}

/**
 * read_prompt - Read lines in the prompt
 *
 * Return: Buffer readed or NULL if EOF was found
 **/
char *read_prompt()
{
	char *bufj;
	short resj;
	size_t sizej;

	bufj = NULL;

	resj = getline(&bufj, &sizej, stdin);

	if (resj == EOF)
	{
		free_memory_p((void *) bufj);
		return (NULL);
	}

	return (bufj);
}

/**
 * start_prompt - Loop reading text
 *
 * @info: Struct of general information
 *
 * Return: Buffer readed or NULL if EOF was found
 **/
void start_prompt(general_t *info)
{
	char *buffj;
	char **argumentsj;
	char *pathj;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		prompt(info);

		path = _getenv("PATH");
		is_current_path(pathj, info);

		info->environment = pathj;
		buffj = read_prompt();
		if (buffj == NULL)
		{
			print(info->mode == INTERACTIVE ? "exit\n" : "");
			free(pathj);
			break;
		}

		info->n_commands++;
		if (buffj[0] != '\n')
		{
			argumentsj = split_words(buffj, " \t\n");

			info->argumentsj = argumentsj;
			info->buffer = buffj;
			analyze_patterns(info, argumentsj);
			analyze(argumentsj, info, buffj);

			free_memory_pp((void *) argumentsj);
		}

		free_memory_p((void *) buffj);
		free_memory_p((void *) pathj);
	}

}

/**
 * sigintHandler - Handler for SIGINT
 *
 * @sig_num: Unused parameter
 **/
void sigintHandler(int sig_num)
{
	(void) sig_num;

	signal(SIGINT, sigintHandler);
	print("\n$ ");
	fflush(stdout);
}
