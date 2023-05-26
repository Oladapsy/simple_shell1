#include "main.h"

/**
 * _putchar - Print a character to STDOUT
 *
 * @q: Character to print
 *
 * Return: On success 1
 * On error -1
 **/
int _putchar(char q)
{
	return (write(STDOUT, &q, 1));
}

/**
 * print_it - Print a message to STDOUT
 *
 * @msgj: Message to print
 *
 * Return: On success number of bytes printed
 * On errror -1, and set the error
 **/
int print_it(char *msgj)
{
	return (print_to_fd(msgj, STDOUT));
}
