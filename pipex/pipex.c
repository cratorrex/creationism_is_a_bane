/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:49:15 by thtay             #+#    #+#             */
/*   Updated: 2026/04/09 16:49:16 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
//   $>  < txt.txt grep 'lo' | sed -r 's/r/--/g' > edit.txt
//```
//
int	main(int count, char *vec)
{

}
