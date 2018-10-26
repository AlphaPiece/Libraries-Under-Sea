/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:30:13 by zwang             #+#    #+#             */
/*   Updated: 2018/10/25 21:31:47 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char *delim)
{
	char	**arr;
	int		i;
	int		j;
	int		k;
	int		str_num;

	str_num = ft_strnsepc(s, delim);
	if (!s || !(arr = (char **)malloc(sizeof(char *) * (str_num + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (i < str_num)
	{
		arr[i] = ft_strnew(ft_strclen(&s[k], delim) + 1);
		while (s[k] && ft_strchr(delim, s[k]))
			k++;
		j = 0;
		while (s[k] && !ft_strchr(delim, s[k]))
			arr[i][j++] = s[k++];
		arr[i++][j] = '\0';
	}
	arr[i] = NULL;
	return (arr);
}
