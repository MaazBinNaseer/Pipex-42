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
#include "pipex.h"

// ?---------------- FREE THE CHILDS AND THE PARENTS 
void free_parent(t_pipex *pipex)
{
    int i;

    i = 0;
    close(pipex->infile);
    close(pipex->outfile);
    while(pipex->cmd_path[i])
    {
        free(pipex->cmd_path[i]);
        i++;
    }
    free(pipex->cmd_path);
}

void free_childs(t_pipex *pipex)
{
    int i;
    i= 0;
    while(pipex->cmd_arg[i])
    {
        free(pipex->cmd_arg[i]);
        i++;
    }
    free(pipex->cmd_arg);
    free(pipex->cmd);
}

// ! ---------- ERRORS MESSAGE 

int message_error(char *error)
{
    write(2, error, ft_strlen(error));
    return (1);
}

void perror_message(char *err)
{
    perror(err);
    exit(EXIT_FAILURE);
}