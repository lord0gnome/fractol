/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 15:05:52 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/20 14:50:21 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_f		init_mandelbrot(t_f f, t_f_data *d)
{
	f.c_r = (f.x - (d->ww / 2)) / f.zoomx + f.xoff;
	f.c_i = (f.y - (d->wh / 2)) / f.zoomy + f.yoff;
	f.z_r = 0;
	f.z_i = 0;
	f.i = 0;
	return (f);
}

t_f		init_julia(t_f f, t_f_data *d)
{
	f.c_r = (d->mxj - d->ww / 2) / (f.zoomxlock) + f.xofflock;
	f.c_i = (d->myj - d->wh / 2) / (f.zoomylock) + f.yofflock;
	f.z_r = (f.x - d->ww / 2) / (f.zoomx) + f.xoff;
	f.z_i = (f.y - d->wh / 2) / (f.zoomy) + f.yoff;
	f.i = 0;
	return (f);
}

t_f		init_gnome(t_f f, t_f_data *d)
{
	f.c_r = (f.x - (d->ww / 2)) / f.zoomx + f.xoff;
	f.c_i = (f.y - (d->wh / 2)) / f.zoomy + f.yoff;
	f.z_r = -(((double)((double)d->mxj - d->ww / 2) / (double)(d->ww)));
	f.z_i = -((double)((double)d->myj - d->wh / 2) / (double)(d->wh));
	f.i = 0;
	return (f);
}

t_f		init_moore(t_f f, t_f_data *d)
{
	f.c_r = (f.x - (d->ww / 2)) / f.zoomx + f.xoff;
	f.c_i = (f.y - (d->wh / 2)) / f.zoomy + f.yoff;
	f.z_r = -((double)((double)f.color.rb / 255) + (double)f.color.bb / 255);
	f.z_i = (double)((double)f.color.gb / 255 - (double)f.color.bb / 255);
	f.i = 0;
	return (f);
}
