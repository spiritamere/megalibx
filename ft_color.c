/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:40:41 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/22 11:44:47 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "megalibx.h"

int	ft_get_int_color(t_color_rgb rgb)
{
	int	color;

	color = rgb.r;
	color = color * 256 + rgb.g;
	color = color * 256 + rgb.b;
	return (color);
}

t_color_rgb	ft_get_struct_color(int color)
{
	t_color_rgb	rgb;

	rgb.b = color % 256;
	color /= 256;
	rgb.g = color % 256;
	color /= 256;
	rgb.r = color;
	return (rgb);
}

int	ft_get_color_gradient(t_gradient gradient)
{
	int	mix;
	int	r;
	int	g;
	int	b;

	b = (gradient.color2 % 256 - gradient.color1 % 256) * gradient.step
		/ gradient.step_max + gradient.color1 % 256;
	gradient.color2 /= 256;
	gradient.color1 /= 256;
	g = (gradient.color2 % 256 - gradient.color1 % 256) * gradient.step
		/ gradient.step_max + gradient.color1 % 256;
	gradient.color2 /= 256;
	gradient.color1 /= 256;
	r = (gradient.color2 % 256 - gradient.color1 % 256) * gradient.step
		/ gradient.step_max + gradient.color1 % 256;
	mix = b + g * 256 + r * 256 * 256;
	return (mix);
}
