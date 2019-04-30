/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_dlist_delete_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:58:31 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/29 19:48:53 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libef.h"

t_dlist	*ef_dlist_delete_node(t_dlist *list, t_dlist *node)
{
	list = ef_dlist_remove_node(list, node);
	ef_dlist_free_one(node);
	return (list);
}