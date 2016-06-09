/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 17:26:45 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/09 22:14:29 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	set_color_ntense(int n, t_color c)
{
	c.ntense += n;
	return (c);
}

t_color	invert_colors(t_color c)
{
	c.r = 255 - c.r;
	c.g = 255 - c.g;
	c.b = 255 - c.b;
	c.rb = c.r;
	c.gb = c.g;
	c.bb = c.b;
	return (c);
}

t_color init_color(t_color c)
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

t_color	det_color(t_color c, int i)
{
	i %= c.imax;
	if (c.rb + i > 255) //red
		c.rup = 0;
	if (c.gb + i > 255) //green
		c.gup = 0;
	if (c.bb + i > 255) //blue
		c.bup = 0;
	if (c.rb - i  <= 0) //red
		c.rup = 1;
	if (c.gb - i <= 0) //green
		c.gup = 1;
	if (c.bb - i <= 0) //blue
		c.bup = 1;

	if (c.rup == 1) //red
		c.r = c.rb + i * c.ntense;
	else
		c.r = c.rb - i * c.ntense;
	if (c.gup == 1) //green
		c.g = c.gb + i * c.ntense;
	else
		c.g = c.gb - i * c.ntense;
	if (c.bup == 1) //blue
		c.b = c.bb + i * c.ntense;
	else
		c.b = c.bb - i * c.ntense;
	return (c);
}

t_f		init_mandelbrot(t_f f, t_f_data *d)
{
	f.c_r = (f.x - (d->ww/2)) / f.zoomx + f.xoff;
	f.c_i = (f.y - (d->wh/2)) / f.zoomy + f.yoff;
	f.z_r = 0;
	f.z_i = 0;
	f.i = 0;
	return (f);
}

t_f		init_julia(t_f f, t_f_data *d)
{
	f.c_r = (d->mxj - d->ww / 2) / (0.5 * d->ww / 2);
	f.c_i = (d->myj - d->wh / 2) / (0.5 * d->wh / 2);
	f.z_r = (f.x - d->ww / 2) / (f.zoomx) + f.xoff;
	f.z_i = (f.y - d->wh / 2) / (f.zoomy) + f.yoff;
	f.i = 0;
	return (f);
}

void	*julia(void	*data)
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
	while (f.x < d->ww)
	{
		f.y = (t->index - 1) * (d->wh / d->threads);
		while (f.y < f.len)
		{
			f = init_julia(f, d);
			while (f.i < f.iter)
			{
				f.tmp = f.z_r;
				f.z_r = f.z_r * f.z_r - f.z_i * f.z_i + f.c_r;
				f.z_i = 2 * f.tmp * f.z_i + f.c_i;
				f.i++;
				/*f.tmp = f.z_r;
				  f.tmp2 = f.z_i;
				  f.z_r = f.tmp * f.tmp - f.tmp2 + f.c_r;
				  f.z_i = 3 * f.tmp * f.tmp * f.tmp2 * f.tmp2 + f.c_i;
				  f.i++;*/
				if (f.z_r * f.z_r + f.z_i * f.z_i > 4)
					break ;
			}
			f.color = det_color(f.color, f.i);
			if (f.i == f.iter)
			{
				f.color.r = -(f.color.r / 4);
				f.color.g = -(f.color.g / 4);
				f.color.b = -(f.color.b / 4);
			}
			if (f.y >= 0 && f.x >= 0 && f.y <= d->wh && f.x <= d->ww)
				ft_putpixel_frct(f.x, f.y, f.color, d);
			f.y++;
		}
		f.x++;
	}
	return (NULL);
}
void	*mandelbrot(void	*data)
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
				f.z_i = 2 * f.tmp * f.z_i + f.c_i;
				f.i++;
			}
			f.color = det_color(f.color, f.i);
			if (f.i == f.iter)
				f.color.r = -f.color.r;
			f.color.g = -f.color.g;
			f.color.b = -f.color.b;
			if (f.y >= 0 && f.x >= 0 && f.y <= d->wh && f.x <= d->ww)
				ft_putpixel_frct(f.x, f.y, f.color, d);
			f.y++;
		}
		f.x++;
	}
	return (NULL);
}
void	*det_frct(void *data)
{
	t_tids *t;
	t_f_data *d;

	t = (t_tids *)data;
	d = t->data;

	if (!ft_strcmp("mandelbrot",d->name))
		mandelbrot(data);
	else if (!ft_strcmp("julia", d->name))
		julia(data);
	pthread_exit(0);	
}


void	modify_image(t_f_data *d)
{
	int		index;

	index = 0;
	if (d->threads)
	{
		while (index < d->threads)
		{
			d->tids[index].index = index + 1;
			d->tids[index].data = (t_f_data *)d;
			pthread_create(&d->tids[index].thread, NULL, det_frct, (void *)&d->tids[index]);
			index++;
		}
		index = 0;
		while (index < d->threads)
			pthread_join((d->tids[index++].thread), NULL);
	}
	mlx_put_image_to_window(d->init, d->window, d->image, 0 , 0);
	mlx_string_put(d->init, d->window, 0, 0, 0xffffff, ft_itoa(d->frct->iter));
	mlx_string_put(d->init, d->window, 0, 24, 0xffffff, ft_itoa(d->woosh));
	mlx_string_put(d->init, d->window, 0,48, 0xffffff, ft_itoa(d->frct->color.r));
	mlx_string_put(d->init, d->window, 0,72, 0xffffff, ft_itoa(d->frct->color.g));
	mlx_string_put(d->init, d->window, 0, 96, 0xffffff, ft_itoa(d->frct->color.b));
	mlx_string_put(d->init, d->window, 0, 120, 0xffffff, ft_itoa(d->frct->iter));
}
