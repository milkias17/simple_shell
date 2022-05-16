#include "main.h"

/**
	* print_prompt - prints the prompt of the shell
	* Description: prints the prompt of the shell
	* Return: void
*/

void print_prompt()
{
	write(1, "#cisfun$ ", 9);
}

/**
	* _strlen - returns the length of a string
	* @string: string to check length of
	* Description: returns the length of a string
	* Return: length of string
*/

int _strlen(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
	* _strcpy - copies the string from src to dest
	* @src: src string
	* @dest: destination string
	* Description: copits the string from src to dest
	* Return: void
*/

void _strcpy(char *src, char *dest)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

/**
	* _strcat - concatenate s1 and s2
	* @s1: string 1
	* @s2: string 2
	* Description: concatenate s1 and s2
	* Return: new string of s1 and s2 combined
*/

char *_strcat(char *s1, char *s2)
{
	int length_s1 = _strlen(s1);
	int length_s2 = _strlen(s2);
	char *result = malloc((length_s1 + length_s2) * sizeof(char));
	int i = 0;

	while (i < length_s1)
	{
		result[i] = s1[i];
		i++;
	}

	while ((i - length_s1) < length_s2)
	{
		result[i] = s2[i - length_s1];
		i++;
	}
	return (result);
}

/**
	* _strcmp - compares two strings
	* Description: compares two strings
	* Return: int
*/
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
		i++;
	}

	return (1);
}
