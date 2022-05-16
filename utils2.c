#include "main.h"
#include <stdio.h>
#include <stdlib.h>


/**
	* is_builtin - checks whether a commands is a builtin or not
	* Description: checks whether a commands is a builtin or not
	* Return: int
*/
int is_builtin(char *cmd)
{
	return (_strcmp(cmd, "exit"));
}

/**
	* execute_cmd - executes a command
	* Description: executes a command
	* Return: void
*/
void execute_cmd(char *pg_name, char **cmd_and_args)
{
	int exec_status;

	if (is_builtin(cmd_and_args[0]))
	{
		_exit(-1);
	}
	exec_status = execve(cmd_and_args[0], cmd_and_args, environ);
	if (exec_status == -1)
	{
		perror(pg_name);
	}


}
