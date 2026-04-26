/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:21:20 by thtay             #+#    #+#             */
/*   Updated: 2025/12/19 21:21:22 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// read, malloc, free
//
//

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# include <unistd.h>
# include <stdlib.h>
//# include <stdio.h>

char	*get_next_line(int fd);

//5 Helper Functions :thinking:
ssize_t	gnl_strlen(const char *str);
char	*gnl_strdup(char *str);
char	*gnl_strljoin(char *s1, char *s2);
ssize_t	gnl_memnchr(char *str, ssize_t size);

#endif
