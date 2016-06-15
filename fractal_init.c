/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 15:05:52 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/15 15:06:30 by guiricha         ###   ########.fr       */
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

t_f		init_newton(t_f f, t_f_data *d)
{
	f.c_r = (f.x - (d->ww / 2)) / f.zoomx + f.xoff;
	f.c_i = (f.y - (d->wh / 2)) / f.zoomy + f.yoff;
	f.z_r = 0;
	f.z_i = 0;
	f.i = 0;
	return (f);
}
