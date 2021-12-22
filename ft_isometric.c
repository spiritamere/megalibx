/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:48:31 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/22 11:49:00 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "megalibx.h"

t_coord_2d	ft_isometric(t_coord_3d coord, t_camera *cam)
{
	t_coord_2d	coord_2d;
	int			zoom;

	zoom = cam->zoom;
	if (zoom < 1)
		zoom = 1;
	coord_2d.x = zoom * 0.7 * (coord.x - coord.y) + cam->coord.x;
	coord_2d.y = zoom * (0.8 * coord.z - 0.4 * (coord.x + coord.y)) * -1
		+ cam->coord.y;
	return (coord_2d);
}
