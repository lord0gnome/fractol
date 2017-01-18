/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnome.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:35:13 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/20 14:42:49 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	gnome_ext(t_tids *t, t_f f, t_f_data *d)
{
	while (f.x < d->ww)
	{
		f.y = (t->index - 1) * (d->wh / d->threads);
		while (f.y < f.len)
		{
			f = init_gnome(f, d);
			while (f.i < f.iter)
			{
				f.tmp = f.z_r;
				f.z_r = f.z_r * f.z_r - f.z_i * f.z_i + f.c_r;
				f.z_i = ((f.tmp + f.tmp) * f.z_i + f.c_i);
				f.i++;
				if (f.z_r * f.z_r + f.z_i * f.z_i > 4)
					break ;
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

void	*gnome(void *data)
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
	f.len = (t->index) * (d->wh / d->threads);
	gnome_ext(t, f, d);
	return (NULL);
}
