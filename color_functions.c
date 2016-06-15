/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 20:08:39 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/15 16:57:02 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	boring_color(t_color c, int i, int imax)
{
	int	b;

	b = i % 255;
	c.r = b;
	c.g = b;
	c.b = b;
	if (i == imax)
	{
		c.r = 128;
		c.g = 128;
		c.b = 128;
	}
	return (c);
}

t_color	set_color_ntense(int n, t_color c)
{
	c.ntense += n;
	return (c);
}

t_color	invert_colors(t_color c)
{
	c.r = -c.r;
	c.g = -c.g;
	c.b = -c.b;
	if (c.r == 0)
		c.r = 255;
	if (c.g == 0)
		c.g = 255;
	if (c.b == 0)
		c.b = 255;
	c.rb = c.r;
	c.gb = c.g;
	c.bb = c.b;
	return (c);
}

t_color	init_color(t_color c)
{
	c.r = rand() % 235;
	c.g = rand() % 235;
	c.b = rand() % 235;
	c.rb = c.r;
	c.gb = c.g;
	c.bb = c.b;
	c.rup = 1;
	c.gup = 1;
	c.bup = 1;
	return (c);
}

t_color	det_color(t_color c, int new, int new2)
{
	int i;

	i = new % c.imax;
	if (c.rb + i > 255)
		c.rup = 0;
	else if (c.rb - i <= 0)
		c.rup = 1;
	if (c.gb + i > 255)
		c.gup = 0;
	else if (c.gb - i <= 0)
		c.gup = 1;
	if (c.bb + i > 255)
		c.bup = 0;
	else if (c.bb - i <= 0)
		c.bup = 1;
	c.r = c.rb + i * c.ntense;
	c.g = c.gb + i * c.ntense;
	c.b = c.bb + i * c.ntense;
	if (new == new2)
	{
		c.r = c.r == 0  || c.r == 255 ? 125 : -c.r;
		c.g = c.g == 0  || c.g == 255 ? 125 : -c.g;
		c.b = c.b == 0  || c.b == 255 ? 125 : -c.b;
	}
	return (c);
}
