/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:49:07 by thtay             #+#    #+#             */
/*   Updated: 2026/04/09 16:49:08 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  insert {navyseal.copypasta}

#include "libft/libft.h"
#include "gnl/get_next_line_bonus.h"
/*
	<unistd.h>
	close, read, write, access, dup, dup2, execve
	fork, pipe, unlink

	<stdlib.h> >>> malloc, free, exit
	
	<string.h> >>> strerror
*/
#include <errno.h>
// >>> && <stdio.h> >> perror
#include <fcntl.h>
// >>> open
#include <sys/wait.h>
// >>> wait, waitpid

typedef int	t_fpipe[2];

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	*limit;

	t_fpipe	*pipette;
}	t_pipex;

int		ft_strmatch(char *vec, char *match);
int		ft_arrlen(char **s);

void	px_exec(char **vec, int *pipes, int i);
void	px_exit(char **split, char *join);

