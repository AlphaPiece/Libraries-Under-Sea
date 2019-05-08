/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_htable_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 09:52:15 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/08 13:36:52 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libef.h"

t_kvpair	*ef_htable_pop(t_htable *table)
{
	int			i;
	t_dlist		*list;
	t_kvpair	*pair;

	for (i = 0; i < table->capacity; i++)
		if ((list = table->array[i]))
		{
			table->array[i] = ef_dlist_unlink(list, list);
			break ;
		}
	pair = list->data;
	ef_dlist_free(list, NULL, ONE);
	table->size--;
	return (pair);
}
