/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:20:43 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/22 11:45:29 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "megalibx.h"

t_global	*ft_init_mlx(void)
{
	t_data		img;
	t_global	*global;

	global = malloc(sizeof (t_global) + 1);
	if (!global)
		return (0);
	global->mlx = mlx_init();
	if (!global->mlx)
	{
		free(global);
		return (0);
	}
	mlx_do_key_autorepeaton(global->mlx);
	global->win = mlx_new_window(global->mlx, SIZE_X, SIZE_Y, "global");
	if (!global->win)
	{
		free(global);
		return (0);
	}
	img.img = mlx_new_image(global->mlx, SIZE_X, SIZE_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	global->data = img;
	return (global);
}
