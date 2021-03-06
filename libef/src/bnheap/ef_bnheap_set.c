/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_bnheap_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 22:15:16 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/17 22:28:13 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ef_bnheap.h"

void	ef_bnheap_set(t_bnheap *heap, void *key, void *value)
{
	if (heap)
		ef_bnheap_insert(heap, ef_bnnode_create(key, value));
}
