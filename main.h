#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stddef.h>

int _strlen(char *string);
void print_prompt();
void _strcpy(char *src, char *dest);
char *_strcat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
#endif
