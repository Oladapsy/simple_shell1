#include "main.h"

/**
 * split_words ` - Split a line into words
 *
 * @line: Line to spli
 * @sep: Delimiters for split the words
 *
 * Return: Set of words
 **/
char **split_words(char *line, const char *sep)
{
	char **wordsj, **tmpj, *tokenj;
	size_t new_sizej, old_sizej;

	old_sizej = sizeof(char *);
	words = malloc(old_sizej);
	if (wordsj != NULL)
	{
		new_sizej = 1;
		tokenj = strtok(line, sep);
		while (tokenj)
		{
			if (tokenj[0] == '#')
				break;
			tmpj = _realloc(wordsj, old_sizej, (new_sizej + 1) * sizeof(char *));
			old_sizej = (new_sizej + 1) * sizeof(char *);
			if (tmpj == NULL)
				break;

			wordsj = tmpj;
			++new_sizej;

			words[new_sizej - 2] = malloc(_strlen(tokenj) + 1);
			if (wordsj == NULL)
			{
				free(wordsj);
				free(tmpj);
			}

			if (wordsj[new_sizej - 2] != NULL)
				_strcpy(wordsj[new_sizej - 2], tokenj);

			tokenj = strtok(NULL, sep);

			tmpj = NULL;
		}

		wordsj[new_sizej - 1] = NULL;
	}

	return (wordsj);
}

/**
 * join_words - Join 3 words with a separator
 * Description: Result -> w1.sep.w2.sep.nl
 * @word1: Word1 to join
 * @word2: Word2 to join
 * @word3: Word3 to join
 * @sep: Separator between the words
 *
 * Return: Line composed by 3 parts followed by a separator and
 * end by a new line
 **/
char *join_words(char *word1, char *word2, char *word3, const char *sep)
{
	char *auxj;
	short size_str1j, size_str2j, size_str3j, size_sepj;

	size_str1j = size_str2j = size_sepj = 0;

	if (word1 != NULL)
		size_str1j = _strlen(word1);
	else
		word1 = "";

	if (word2 != NULL)
		size_str2j = _strlen(word2);
	else
		word2 = "";

	if (word3 != NULL)
		size_str3j = _strlen(word3);
	else
		word3 = "";

	if (sep != NULL)
		size_sepj = _strlen((char *)sep);
	else
		sep = "";

	auxj = malloc(size_str1j + size_str2j + size_sepj + size_str3j + size_sepj + 2);
	if (auxj == NULL)
		return (NULL);

	auxj = _strcpy(auxj, word1);
	auxj = _strcat(auxj, (char *)sep);
	auxj = _strcat(auxj, word2);
	auxj = _strcat(auxj, (char *)sep);
	auxj = _strcat(auxj, word3);
	auxj = _strcat(auxj, "\n");

	return (auxj);
}
