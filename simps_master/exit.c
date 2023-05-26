#include "main.h"

/**
 * bin_exit - Implementation of the exit builtin
 * Description: Free all the memory used and
 * exit with the last status_code
 *
 * @info: Information about the shell
 * @arguments: Arguments received
 **/
void bin_exit(general_t *info, char **arguments)
{
	short status_codej, statusj;

	statusj = _TRUE;
	if (arguments[1] != NULL)
		statusj = number_controller(info, arguments[1]);

	if (statusj == _FALSE)
	return;

	status_codej = info->status_codej;

	free_memory_pp((void **) arguments);
	free_memory_p((void *) info->buffer);
	free_memory_p((void *) info->environment);
	free_memory_p((void *) info);

	exit(status_codej);
}

/**
 * number_controller - Control the argument of exit
 *
 * @info: General information about the shell
 * @number: Argument of the builtin
 *
 * Return: If the actual argument is valid, return _TRUE
 * if not, return _FALSE
 **/
int number_controller(general_t *info, char *number)
{
	short _numberj;

	_numberj = _atoi(number);

	if (_numberj < 0 || contains_letter(number))
	{
		info->status_code = 2;
		info->error_code = _CODE_ILLEGAL_NUMBER;
		error_extra(info, number);
		return (_FALSE);
	}

	if (_numberj > 255)
		info->status_code = _numberj % 256;
	else
		info->status_code = _numberj;

	return (_TRUE);
}
