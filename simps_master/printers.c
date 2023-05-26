#include "main.h"

/**
 *  * _putchar_to_fd - Print a character to a specific file
 *   * descriptor
 *    *
 *     * @q: Character to print
 *      * @fdj: Place to print the character
 *       *
 *        * Return: On success 1.
 *         * On error, -1 is returned, and errno is set appropriately.
 *          **/
int _putchar_to_fd(char q, int fdj)
{
		return (write(fdj, &q, 1));
}


/**
 *  * print_to_fd - Print a string
 *   *
 *    * @msgj: Strin to print in the fd specified
 *     * @fdj: File descriptor to print
 *      *
 *       * Return: On success numbers of bytes printed.
 *        * On error, -1 is returned, and errno is set appropriately.
 *         **/
int print_to_fd(char *msgj, int fdj)
{
		short sizej;

			sizej = _strlen(msgj);

				return (write(fdj, msgj, sizej));
}
