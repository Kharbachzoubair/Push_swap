/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:28:35 by zkharbac          #+#    #+#             */
/*   Updated: 2025/03/27 13:28:48 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rangeof(int len)
{
	if (len < 20)
		return (3);
	return (len / 20 + 10);
}
