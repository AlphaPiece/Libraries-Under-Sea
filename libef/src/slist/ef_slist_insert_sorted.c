/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_slist_insert_sorted.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 22:34:27 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/30 07:13:24 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ef_slist.h"

t_slist	*ef_slist_insert_sorted(t_slist *list, void *data, f_cmp cmp)
{
	t_slist	*new_node;
	t_slist	*node;

	if (!list || !cmp || cmp(data, list->data) <= 0)
		return (ef_slist_prepend(list, data));
	new_node = ef_slist_alloc();
	new_node->data = data;
	for (node = list; node->next && cmp(node->next->data, data) < 0; )
		node = node->next;
	new_node->next = node->next;
	node->next = new_node;
	return (list);
}
