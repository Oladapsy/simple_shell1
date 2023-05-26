#include "main.h"

/**
 * is_executable - Check if a filename have permissions
 * for run
 *
 * @filename: Filename to check
 *
 * Return: On success, PERMISSIONS
 * On error, NON_PERMISSIONS
 **/
int is_executable(char *filename)
{
	struct statj stats;

	if (statj(filename, &stats) == 0)
	{
		if (stats.st_mode & X_OK)
			return (PERMISSIONS);
		else
			return (NON_PERMISSIONS);
	}

	return (NON_FILE);
}

/**
 * is_file - Check if is a file or binary
 * Description: Lool for excute permissions and
 * if is a file
 *
 * @file: File to check
 *
 * Return: If is a file with the correct permissions, PERMISSIONS
 * If is a file but not have permissions or doesn't exists, NON_PERMISSIONS
 * If is not a file, NON_FILE
 **/
int is_file(char *file)
{
	short q, sizej;

	sizej = _strlen(file);
	q = 0;
	while (q < sizej)
	{
	if (file[q] == '/')
	return (is_executable(file));
	q++;
	}
	return (NON_FILE);
}
