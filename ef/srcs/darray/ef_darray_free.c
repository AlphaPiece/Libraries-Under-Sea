/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_darray_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:22:05 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/04 23:35:52 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libef.h"

void	ef_darray_free(t_darray *darr)
{
	if (darr)
	{
		ef_darray_clear(darr);
		free(darr->data);
		free(darr);
	}
}
