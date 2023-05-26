#include "main.h"

/**
 * print_error - Print a message to STDERR
 *
 * @msgj: Message to print
 *
 * Return: Number of bytes printed
 **/
int print_error(char *msgj)
{
	return (print_to_fd(msgj, STDERR));
}
