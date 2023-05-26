#include "main.h"

/**
 * replacement - Entry point
 * @info: input
 * @index: input
 * @string: input
 * Return: string
**/

char *replacement(general_t *info, int *index, char *string)
{
	char *tmpj;
	char symbolj;

	(void) index;

	symbol = *string;
	if (symbol != '?' && symbol != '$')
	{
		tmpj = replace_env(info, string);
		return (tmp);
	}

	tmpj = (symbol == '$') ? to_string(info->pid) :
		to_string(info->status_code);

	return (tmpj);
}

/**
 * replace_env - Entry Point
 * @info: input
 * @environment: input
 * Return: string
**/

char *replace_env(general_t *info, char *environment)
{
	char *envj;

	(void) info;

	envj = _getenv(environment);
	if (envj != NULL)
		return (envj);

	return (NULL);
}
