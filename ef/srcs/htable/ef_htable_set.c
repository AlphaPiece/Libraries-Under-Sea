/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_htable_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 10:31:28 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/09 15:54:23 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libef.h"

void	ef_htable_set(t_htable *table, void *key, void *value)
{
	t_dlist	*node;

	if ((node = ef_htable_find(table, key)))
		HT_PAIR(node)->value = value;
	else
		ef_htable_insert(table, ef_kvpair_new(key, value));
}
