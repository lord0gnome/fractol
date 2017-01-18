/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:36:22 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/20 14:41:50 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ext(t_tids *t, t_f f, t_f_data *d)
{
	while (f.x < d->ww)
	{
		f.y = (t->index - 1) * (d->wh / d->threads);
		while (f.y <= f.len)
		{
			f = init_mandelbrot(f, d);
			while (f.z_r * f.z_r + f.z_i * f.z_i < 4 && f.i < f.iter)
			{
				f.tmp = f.z_r;
				f.z_r = f.z_r * f.z_r - f.z_i * f.z_i + f.c_r;
				f.z_i = 2 * fabs(f.tmp) * fabs(f.z_i) + f.c_i;
				f.i++;
			}
			if (d->crazy)
				f.color = det_color(f.color, f.i, f.iter);
			else
				f.color = boring_color(f.color, f.i, f.iter);
			if (f.y >= 0 && f.x >= 0 && f.y <= d->wh && f.x <= d->ww)
				ft_putpixel_frct(f.x, f.y, f.color, d);
			f.y++;
		}
		f.x++;
	}
}

void	*burning(void *data)
{
	t_tids		*t;
	t_f			*ff;
	t_f			f;
	t_f_data	*d;

	t = (t_tids *)data;
	d = (t_f_data *)t->data;
	ff = (t_f *)d->frct;
	f = (*ff);
	f.x = 0;
	f.len = ceil((double)(t->index) * (double)(d->wh / d->threads));
	burning_ext(t, f, d);
	return (NULL);
}
