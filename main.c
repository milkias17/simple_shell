#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
	* split_cmd - splits user input
	* @string: string inputted from user
	* @bufsize: buffer size needed for user inputted string
	* Description: splits user input into command and arguments
	* Return: array of strings containing the command and its arguments
*/

char **split_cmd(char *string, size_t bufsize)
{
	const char *delims = " \t\n\r\a";
	char *tmp_string = malloc(bufsize);
	char **splitted_string = malloc(bufsize * sizeof(char *));
	char *token;
	int position = 0;

	_strcpy(string, tmp_string);

	token = strtok(tmp_string, delims);
	while (token != NULL)
	{
		splitted_string[position] = token;
		position++;

		if (position > bufsize)
		{
			bufsize += bufsize;
			splitted_string = realloc(splitted_string, bufsize * sizeof(char *));
		}
		token = strtok(NULL, delims);
	}
	splitted_string[position] = NULL;

	return (splitted_string);
}

/**
	* take_user_cmd - Take in user input for command execution
	* Description: Take in user input for command execution
	* Return: An array of strings containing the command and its arguments
*/

char **take_user_cmd()
{
	long status;
	char *string;
	size_t bufsize = 0;
	char **splitted_cmd;

	status = getline(&string, &bufsize, stdin);

	if (status == -1)
	{
		return (NULL);
	}
	splitted_cmd = split_cmd(string, bufsize);

	return (splitted_cmd);
}

/**
	* is_builtin - checks whether a commands is a builtin or not
	* Description: checks whether a commands is a builtin or not
	* Return: int
*/
int is_builtin(char *cmd)
{
	// TODO: implement much better is_builtin where if it is builtin return a function and so on
	return _strcmp(cmd, "exit");
}

/**
	* execute_cmd - executes a command
	* Description: executes a command
	* Return: void
*/
void execute_cmd(char *pg_name, char **cmd_and_args)
{
	int exec_status;
	extern char **environ;

	if (is_builtin(cmd_and_args[0]))
	{

	}
	exec_status = execve(cmd_and_args[0], cmd_and_args, environ);
	if (exec_status == -1)
	{
		perror(pg_name);
	}


}

/**
	* main_loop - main loop logic
	* @pg_name: name of the current program/process
	* Description: main loop logic for the simple shell
	* Return: status code for the main function to return
*/

int main_loop(char *pg_name)
{
	pid_t my_pid;
	int status;
	char **cmd_and_args;

	while (1)
	{
		print_prompt();
		cmd_and_args = take_user_cmd();

		if (cmd_and_args == NULL)
		{
			return (1);
		}

		my_pid = fork();
		char exec_status;

		if (my_pid == 0)
		{
			execute_cmd(pg_name, cmd_and_args);
		}

		else
		{
			wait(&status);
		}
	}
}

/**
	* main - Runs the main loop of the shell
	* @argc: number of arguments given to program
	* @argv: list of arguments passed to program
	* Description: Runs the main loop of the shell
	* Return: status code of program
*/

int main(int argc, char *argv[])
{
	return (main_loop(argv[0]));
}
