#include "main.h"

void print_prompt()
{
	write(1, "#cisfun$ ", 9);
}

int _strlen(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		i++;
	}

	return (i);
}

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
