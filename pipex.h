/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:18:10 by mbin-nas            #+#    #+#           */
/*   Updated: 2022/11/11 11:18:10 by mbin-nas          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

//* Main Libraries 
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdbool.h>

//? Error Files handling 
#define ERR_INFILE "Infile" 
#define ERR_OUTFILE "Outfile"
#define ERR_INPUT "Invalid number of arguments.\n"
#define ERR_PIPE "Pipe"
#define ERR_CMD "Command not found\n"
#define ERR_PATH "Path not found\n"


//// Struct definintion 
typedef struct pipex 
{
    pid_t pid1; 
    pid_t pid2; 
    int fd[2];
    int infile;
    int outfile; 
    char *path;
    char **cmd_path;
    char **cmd_arg;
    char *cmd;

} t_pipex;

//// Pipex functions 
char *get_command(char **path, char *cmd);
void first_child_process(t_pipex pipex, char *argv[], char *envp[]);
void second_child_process(t_pipex pipex, char *argv[], char *envp[]);
void close_pipes (t_pipex *pipex);

void free_parent(t_pipex *pipex);
void free_childs(t_pipex *pipex);
char *find_path(char **envp);

////Libft Functions
char	**ft_split(char const *str, char c);
char	*ft_strjoin(char const *str1, char const *str2);
int	    ft_strncmp(const char *s1, const char *s2, size_t num);
size_t	ft_strlen(const char *c);
char			*ft_substr(char const *s, unsigned int start, size_t len);

//! Error messages 
int message_error(char *error);
void perror_message(char *err);
#endif