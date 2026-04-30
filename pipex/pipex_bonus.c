/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:49:15 by thtay             #+#    #+#             */
/*   Updated: 2026/04/09 16:49:16 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	px_init(t_pipex *cntl, int count, char **vec, int i);

// basic requirements
// ./pipex {file1} {cmd1} {cmd2} {file2}
// ` $> < file1 cmd1 | cmd2 > file2 `
// "< txt.txt {CMD1} | {CMD2} > edit.txt"
//
//```
// wherein redirects::
//  < stdin | | > stdout
//   >  : Write File (Overwrite)
//   >> : Append File
//   <  : Takes input from file (instead of keyboard)
//	 << : Heredoc (Limiter symbol)
//```
//--
//```
// ./pipex txt.txt "grep 'lo'" "sed -r 's/r/--/g'" edit.txt
//    $> < txt.txt grep 'lo' | sed -r 's/r/--/g' > edit.txt
//```
//--

//```
// ./pipex here_doc LIMITER cmd1 cmd2 outfile
//      $>  cmd1 << LIMITER | cmd2 >> outfile
//```
static void	px_heredoc(t_pipex *cntl, int count, char **vec, int i)
{
	cntl->infile = 0;
	cntl->outfile = open(vec[count - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	cntl->limit = vec[2];
	cntl->pipette = ft_calloc(sizeof(t_fpipe) * (count - 5), 1);
	if (!cntl->pipette)
		exit(1);
	while (i < count - 5)
	{
		if (pipe(cntl->pipette[i]) == -1)
		{
			free(cntl->pipette);
			exit(1);
		}
		i++;
	}
	cntl->pipe_size = i;
	px_hd_open(cntl, vec);
	while (i < (count - 6))
	{
		px_hd_mid(cntl, i, vec);
		i++;
	}
	px_hd_close(cntl, i, vec);
	px_clean(cntl);
}

static void	px_normal(t_pipex *cntl, int count, char **vec)
{
	int		i;

	i = 0;
	px_init(cntl, count, vec, i);
	px_openi(cntl, vec);
	while (i < (count - 5))
	{
		px_mid(cntl, i, vec);
		i++;
	}
	px_closef(cntl, i, vec);
	px_clean(cntl);
}

static void	px_init(t_pipex *cntl, int count, char **vec, int i)
{
	cntl->infile = open(vec[1], O_RDONLY);
	if (cntl->infile < 0)
	{
		ft_printf("pipex: Infile not found.");
		close(0);
		close(1);
		close(2);
		exit(1);
	}
	cntl->outfile = open(vec[count - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	cntl->limit = "";
	cntl->pipette = ft_calloc(sizeof(t_fpipe) * (count - 4), 1);
	if (!cntl->pipette)
		exit(1);
	while (i < count - 4)
	{
		if (pipe(cntl->pipette[i]) == -1)
		{
			free(cntl->pipette);
			exit(1);
		}
		i++;
	}
	cntl->pipe_size = i;
}

int	main(int count, char **vec)
{
	t_pipex	cntl;

	if (count >= (4 + 1))
	{
		if (count >= (5 + 1) && ft_strmatch(vec[1], "here_doc"))
			px_heredoc(&cntl, count, vec, 0);
		else
			px_normal(&cntl, count, vec);
	}
	else
	{
		ft_printf("Expected 4+ args: file1, cmd1, cmd2, [...], file2.\n");
		ft_printf("Alt accept: 'here_doc', LIMITER, cmd1, cmd2, file.\n");
	}
	close(0);
	close(1);
	close(2);
}

//to use execve we need to fork and dup and then pipe into???
