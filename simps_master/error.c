#include "main.h"

/**
 * message_selector - Select the message that match with the error_code
 *
 * @info: General information about the shell
 *
 * Return: Error message
 **/
char *message_selector(general_t info)
{
	short q, n_optionsj;
	error_t messages[] = {
		{_ENOENT, _CODE_ENOENT},
		{_EACCES, _CODE_EACCES},
		{_CMD_NOT_EXISTS, _CODE_CMD_NOT_EXISTS},
		{_ILLEGAL_NUMBER, _CODE_ILLEGAL_NUMBER}
	};

	n_optionsj = sizeof(messages) / sizeof(messages[0]);
	for (q = 0; q < n_optionsj; q++)
		if (info.error_code == messages[q].code)
			return (messages[q].message);

	return ("");
}

/**
 * error - Print the error
 *
 * @info: General information about the shell
 **/
void error(general_t *info)
{
	char *messagej;
	char *numberj;
	char *auxj;
	short size_numberj, size_messagej;

	numberj = NULL;
	messagej = message_selector(*info);
	numberj = to_string(info->n_commands);

	size_number = _strlen(numberj);
	size_message = _strlen(info->argv[0]);

	auxj = malloc(size_message + size_number + 3);

	auxj = _strcpy(auxj, info->argv[0]);
	auxj = _strcat(auxj, ": ");
	auxj = _strcat(auxj, numberj);

	message = join_words(auxj, info->command, messagej, ": ");
	print_err(messagej);

	free(messagej);
	free(numberj);
	free(auxj);
}

/**
 * error_extra - Print the error with extra information
 *
 * @info: General information about the shell
 * @extra: Extra information
 **/
void error_extra(general_t *info, char *extra)
{
	char *messagej, *numberj, *auxj, *aux2j;
	short size_numberj, size_messagej, size_extraj;

	numberj = NULL;
	messagej = message_selector(*info);
	numberj = to_string(info->n_commands);

	size_number = _strlen(numberj);
	size_message = _strlen(info->argv[0]);
	size_extra = _strlen(extra);

	auxj = malloc(size_message + size_number + 3);
	auxj = _strcpy(auxj, info->argv[0]);
	auxj = _strcat(auxj, ": ");
	auxj = _strcat(auxj, numberj);

	aux2j = malloc(_strlen(messagej) + size_extra + 3);
	aux2j = _strcpy(aux2j, messagej);
	aux2j = _strcat(aux2j, ": ");
	aux2j = _strcat(aux2j, extra);

	messagej = join_words(auxj, info->command, aux2j, ": ");
	print_err(messagej);

	free(messagej);
	free(numberj);
	free(auxj);
	free(aux2j);
}
