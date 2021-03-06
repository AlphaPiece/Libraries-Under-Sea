/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_ntree_insert_child.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:32:42 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/01 12:39:01 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ef_ntree.h"

void	ef_ntree_insert_child(t_ntree *parent, t_ntree *child, int index)
{
	t_ntree	*prev;

	if (!parent || !child)
		return ;
	else if (!parent->children || index <= 0)
		ef_ntree_prepend_child(parent, child);
	else
	{
		for (prev = parent->children; prev->next && --index; prev = prev->next)
			;
		child->prev = prev;
		child->next = prev->next;
		prev->next = child;
		if (child->next)
			child->next->prev = child;
		child->parent = parent;
	}
}
