/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:35:04 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/22 11:44:43 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "megalibx.h"

static void	ft_draw_line_low(t_data *data, t_coord_2d c1,
	t_coord_2d c2, t_gradient grad)
{
	int			dx;
	int			dy;
	int			yi;
	int			d;

	dx = c2.x - c1.x;
	dy = ft_abs(c2.y - c1.y);
	yi = (c2.y - c1.y < 0) * -1 + (c2.y - c1.y >= 0) * 1;
	d = 2 * dy - dx;
	while (c1.x != c2.x)
	{
		ft_put_pixel(data, c1, ft_get_color_gradient(grad));
		grad.step++;
		if (d > 0)
		{
			c1.y += yi;
			d = d + 2 * (dy - dx);
		}
		else
			d = d + 2 * dy;
		if (c1.x < c2.x)
			c1.x += 2;
		c1.x--;
	}
}

static void	ft_draw_line_high(t_data *data, t_coord_2d c1,
	t_coord_2d c2, t_gradient grad)
{
	int			dx;
	int			dy;
	int			xi;
	int			d;

	dx = ft_abs(c2.x - c1.x);
	dy = c2.y - c1.y;
	xi = (c2.x - c1.x < 0) * -1 + (c2.x - c1.x >= 0) * 1;
	d = 2 * dx - dy;
	while (c1.y != c2.y)
	{
		ft_put_pixel(data, c1, ft_get_color_gradient(grad));
		grad.step++;
		if (d > 0)
			c1.x += xi;
		if (d > 0)
			d = d + 2 * (dx - dy);
		else
			d = d + 2 * dx;
		if (c1.y < c2.y)
			c1.y += 2;
		c1.y--;
	}
}

static t_gradient	ft_invert_gradient(t_gradient gradient)
{
	int	tmp;

	tmp = gradient.color1;
	gradient.color1 = gradient.color2;
	gradient.color2 = tmp;
	return (gradient);
}

void	ft_draw_line(t_data *data, t_coord_2d c1, t_coord_2d c2, t_gradient grad)
{
	if (ft_abs(c2.y - c1.y) < ft_abs(c2.x - c1.x))
	{
		grad.step_max = ft_abs(c2.x - c1.x);
		if (c1.x < c2.x)
			ft_draw_line_low(data, c1, c2, grad);
		else
			ft_draw_line_low(data, c2, c1, ft_invert_gradient(grad));
		return ;
	}
	grad.step_max = ft_abs(c2.y - c1.y);
	if (c1.y < c2.y)
		ft_draw_line_high(data, c1, c2, grad);
	else
		ft_draw_line_high(data, c2, c1, ft_invert_gradient(grad));
}
