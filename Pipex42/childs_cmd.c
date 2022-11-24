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

//? Getting the command from the prompt  
char *get_command(char **path, char *cmd){
    char *temp;
    char *get_command;

    while(*path)
    {
        temp = ft_strjoin(*path, "/");
        get_command = ft_strjoin(temp, cmd);
        free(temp);
        if(access(get_command, 0) == 0) //! Error handling if the file is not accessed 
        {
            return (get_command);
        }
        else 
            perror("Error Description: ");
        free(get_command);
        path++;
    }
    return (NULL); //! if nothing happens return Null to me 
}



/* ------------ Creating a Child process function -------------
* We are going to create the First child process here 
* 1. it needs to duplicate the oldfile process to the new file whcih becomes output
* 2. close the first pipe and write out the process so that the second child can read
! 3. Handling the arguements if the commands fail and the child process fail 
* 4. Need to extract the commands from the argument line   
*/

void first_child_process(t_pipex pipex, char *argv[], char *envp[])
{
    dup2(pipex.fd[1], 1);
    close(pipex.fd[0]); 
    dup2(pipex.infile, 0);
    pipex.cmd_arg = ft_split(argv[2], ' ');
    pipex.cmd = get_command(pipex.cmd_path, pipex.cmd_arg[0]);
    if (!pipex.cmd)
    {   
        free_childs(&pipex);
        perror("What kind of error:");
        exit(EXIT_FAILURE);
    }
    execve(pipex.cmd, pipex.cmd_arg, envp);
}

/*--Second Child */
void second_child_process(t_pipex pipex, char *argv[], char *envp[])
{
    dup2(pipex.fd[0], 0);
    close(pipex.fd[1]);
    dup2(pipex.outfile, 1);
    pipex.cmd_arg = ft_split(argv[3], ' ');
    pipex.cmd = get_command(pipex.cmd_path, pipex.cmd_arg[0]);
    if (!pipex.cmd)
    {   
        free_childs(&pipex);
        perror("What kind of error:");
        exit(EXIT_FAILURE);
    }
    execve(pipex.cmd, pipex.cmd_arg, envp);
}

void close_pipes (t_pipex *pipex)
{
    close(pipex->fd[0]);
    close(pipex->fd[1]);
}
