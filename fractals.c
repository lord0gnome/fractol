/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 17:26:45 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/11 17:46:11 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*				  f.tmp2 = f.z_i;*/
/*				  f.z_r = f.tmp * f.tmp - f.tmp2 + f.c_r;*/
/*				  f.z_i = 3 * f.tmp * f.tmp * f.tmp2 * f.tmp2 + f.c_i;*/
/*				  f.i++;*/
void	newton_ext(t_tids *t, t_f f, t_f_data *d)
{
	while (f.x < d->ww)
	{
		f.y = (t->index - 1) * (d->wh / d->threads);
		while (f.y < f.len)
		{
			f = init_newton(f, d);
			while (f.i < f.iter)
			{
				f.tmp = f.z_r;
				f.z_r = f.z_r * f.z_r - f.z_i * f.z_i + f.c_r;
				f.z_i = (f.tmp + f.tmp) * f.z_i + f.c_i;
				f.i++;
				f.tmp = f.z_r;
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

void	*newton(void *data)
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
	newton_ext(t, f, d);
	return (NULL);
}

void	julia_ext(t_tids *t, t_f f, t_f_data *d)
{
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
				f.z_i = (f.tmp + f.tmp) * f.z_i + f.c_i;
				f.i++;
				f.tmp = f.z_r;
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
	julia_ext(t, f, d);
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
				f.z_i = (f.tmp + f.tmp) * f.z_i + f.c_i;
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
	return (NULL);
}

void	*burning(void	*data)
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
	else if (!ft_strcmp("burningship", d->name))
		burning(data);
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
	mlx_string_put(d->init, d->window, 0, 120, 0xffffff, ft_itoa(d->frct->color.imax));
	mlx_string_put(d->init, d->window, 0, 144, 0xffffff, ft_itoa(d->frct->color.ntense));
}
