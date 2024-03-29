/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:18:10 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/02 16:37:51 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex_r(char *argv[], t_pipex pipex, char *envp[])
{
	int	pointer;

	if (pipex.infile > 0)
	{
		pipex.pid1 = fork();
		if (pipex.pid1 == 0)
			first_child_process(pipex, argv, envp);
	}
	if (pipex.outfile > 0)
	{
		pipex.pid2 = fork();
		if (pipex.pid2 == 0)
			second_child_process(pipex, argv, envp);
	}
	close_pipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, &pointer, 0);
	free_parent(&pipex);
	exit(WEXITSTATUS(pointer));
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc != 5)
		return (message_error(ERR_INPUT));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		message_error(ERR_INFILE);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.outfile < 0)
		message_error(ERR_OUTFILE);
	if (pipe(pipex.fd) < 0)
		message_error(ERR_PIPE);
	pipex.path = find_path(envp);
	if (pipex.path == 0)
	{
		message_error(ERR_PATH);
		return (0);
	}
	pipex.cmd_path = ft_split(pipex.path, ':');
	pipex_r(argv, pipex, envp);
	return (0);
}
