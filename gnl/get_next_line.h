/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:03:34 by fasare            #+#    #+#             */
/*   Updated: 2023/06/13 15:04:21 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char			*get_next_line(int fd);
char			*ft_rd_str(int fd, char *input_str);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlen(const char *s);
char			*ft_extract_line(char *input_str, int i);
char			*ft_new_str(char *input_str);
char			*ft_strdup(const char *s1);

#endif