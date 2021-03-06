/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_bheap_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:49:01 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/17 11:19:36 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ef_bheap.h"

int	ef_bheap_size(t_bheap *heap)
{
	return ((heap && heap->array) ? heap->array->length - 1 : 0);
}
