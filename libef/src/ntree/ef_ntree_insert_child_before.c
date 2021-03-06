/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_ntree_insert_child_before.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 09:55:50 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/27 10:30:24 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ef_ntree.h"

void	ef_ntree_insert_child_before(t_ntree *parent, t_ntree *child,
										t_ntree *sibling)
{
	if (!parent || !child)
		return ;
	else if (!parent->children || sibling == parent->children)
		ef_ntree_prepend_child(parent, child);
	else if (!sibling)
		ef_ntree_append_child(parent, child);
	else
	{
		sibling->prev->next = child;
		child->prev = sibling->prev;
		child->next = sibling;
		sibling->prev = child;
		child->parent = parent;
	}
}
