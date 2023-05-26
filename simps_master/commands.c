#include "main.h"

/**
 * analyze - Analyze	the arguments
 *
 * @arguments: Commands and arguments to execute
 * @info: General information about the shell
 * @buff: Line readed
 **/
void analyze(char **arguments, general_t *info, char *buff)
{
	char *cmdj;
	short statusj;

	if (*arguments == NULL || arguments == NULL)
		return;

	cmdj = arguments[0];
	info->command = cmdj;
	if (check_builtin(info, arguments) == _TRUE)
		return;

	statusj = is_file(cmdj);
	if (statusj == NON_PERMISSIONS)
	{
		info->status_code = 126;
		info->error_code = _CODE_EACCES;
		error(info);
		return;
	}

	if (statusj == 1)
	{
		execute(cmdj, arguments, info, buff);
		return;
	}

	if (current_directory(cmd, arguments, buff, info) == _TRUE)
		return;

	info->value_path = which(cmdj, info);
	if (info->value_path != NULL)
	{
		execute(info->value_path, arguments, info, buff);
		free_memory_p((void *) info->value_path);
		return;
	}

	info->status_code = 127;
	info->error_code = _CODE_CMD_NOT_EXISTS;
	error(info);
}
