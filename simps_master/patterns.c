#include "main.h"

/**
 * analyze_patterns - Entry Point
 * @info: input
 * @arguments: input
**/

void analyze_patterns(general_t *info, char **arguments)
{
	short q;

	for (q = 0; arguments[q] != NULL; q++)
		arguments[q] = pattern_handler(info, arguments[q]);
}

/**
 * pattern_handler - Entry Point
 * @info: input
 * @string: input
 * Return: string
**/

char *pattern_handler(general_t *info, char *string)
{
	short q;

	q = 0;
	while (string[q] != '\0')
	{
		if (string[i] == '$' && string[i + 1] != '\0')
			string = replace_value(info, &i, string);
		q++;
	}

	return (string);
}

/**
 * replace_value - Entry Point
 * @info: input
 * @index: input
 * @string: input
 * Return: string
**/

char *replace_value(general_t *info, int *index, char *string)
{
	short q, new_sj, old_sj;
	char *value;

	q = *index;
	q++;

	value = replacement(info, index, string + q);
	if (value == NULL)
	{
		string = _strcpy(string, "");

		return (string);
		;
	}

	old_sj = _strlen(string);
	new_sj = _strlen(value) + 1;

	string = _realloc(string, old_sj, new_sj);
	string = _strcpy(string, value);

	free_memory_p(value);
	*index = q;
	return (string);
}
