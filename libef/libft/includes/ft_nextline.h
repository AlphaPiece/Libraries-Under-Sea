/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:44:39 by zwang             #+#    #+#             */
/*   Updated: 2020/02/05 08:39:39 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NEXTLINE_H
# define FT_NEXTLINE_H

# include "ft_fio.h"

# define BUFF_SIZE 512
# define NL_INDEX (nlc - buffer)
# define MALLOC_FREE(x, y, z) x = y; y = z; free(x);

typedef	struct		s_file
{
	int				fd;
	char			*save;
	struct s_file	*next;
}					t_file;

int					ft_nextline(const int fd, char **line);

#endif
