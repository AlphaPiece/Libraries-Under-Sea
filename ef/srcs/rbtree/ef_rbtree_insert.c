/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_rbtree_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 11:09:33 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/09 15:13:48 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libef.h"

static void	fix_up(t_rbtree *tree, t_rbnode *z)
{
	t_rbnode	*y;

	while (z->parent->color == R)
		if (z->parent == z->parent->parent->left)
		{
			y = z->parent->parent->right;
			if (y->color == R)
			{
				z->parent->color = y->color = B;
				z->parent->parent->color = R;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->right)
					ef_rbtree_left_rotate(tree, (z = z->parent));
				z->parent->color = B;
				z->parent->parent->color = R;
				ef_rbtree_right_rotate(tree, z->parent->parent);
			}
		}
		else
		{
			y = z->parent->parent->left;
			if (y->color == R)
			{
				z->parent->color = y->color = B;
				z->parent->parent->color = R;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->left)
					ef_rbtree_right_rotate(tree, (z = z->parent));
				z->parent->color = B;
				z->parent->parent->color = R;
				ef_rbtree_left_rotate(tree, z->parent->parent);
			}
		}
	tree->root->color = B;
}

void		ef_rbtree_insert(t_rbtree *tree, t_rbnode *z)
{
	t_rbnode	*x, *y;

	if (!tree || !z || z == tree->nil)
		return ;
	y = tree->nil;
	x = tree->root;
	while (x != tree->nil)
	{
		y = x;
		if (tree->cmp_key(z->key, x->key) < 0)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == tree->nil)
		tree->root = z;
	else if (tree->cmp_key(z->key, y->key) < 0)
		y->left = z;
	else
		y->right = z;
	fix_up(tree, z);
	tree->size++;
}