/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:20:07 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/22 11:20:26 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "megalibx.h"

void	ft_put_pixel(t_data *data, t_coord_2d coord, int color)
{
	char	*dst;

	if (coord.x < 0 || coord.x >= SIZE_X || coord.y < 0 || coord.y >= SIZE_Y)
		return ;
	dst = data->addr + (coord.y * data->line_length
			+ coord.x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
