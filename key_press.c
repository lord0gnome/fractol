/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:47:45 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/09 21:59:20 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>
#include <time.h>
#include <stdio.h>
int	key_press(int keycode, t_f_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_image(data->init, data->image);
		mlx_destroy_window(data->init, data->window);
		data->errno = -1;
		print_options(data);
	}
	if (keycode == KEY_C)
	{
		data->frct->color = init_color(data->frct->color);
	}
	if (keycode == KEY_I)
		data->frct->color = invert_colors(data->frct->color);
	if (keycode == KEY_L)
	{
		data->frct->color = set_color_ntense(1 ,data->frct->color);
	}
	if (keycode == KEY_K)
	{
		data->frct->color = set_color_ntense(-1, data->frct->color);
	}
	if (keycode == KEY_DOT && data->frct->color.imax < 255)
		data->frct->color.imax++;
	if (keycode == KEY_COMMA && data->frct->color.imax > 1)
		data->frct->color.imax--;
	if (keycode == KEY_1)
		data->frct->color.ntense = 1;
	if (keycode == KEY_TILT)
		data->woosh = data->woosh ? 0 : 1;
	if (keycode == 27)
		data->frct->iter--;
	if (keycode == 24)
		data->frct->iter++;
	if (keycode == 69) //plus
	{
		data->frct->xoff += (data->mx - (data->ww / 2)) / data->frct->zoomx;
		data->frct->yoff += (data->my - (data->wh / 2)) / data->frct->zoomy;
		data->frct->zoomy *= 1.25;
		data->frct->zoomx *= 1.25;
		data->frct->xoff -= (data->mx - (data->ww / 2)) / data->frct->zoomx;
		data->frct->yoff -= (data->my - (data->wh / 2)) / data->frct->zoomy;
		data->zoomlevel++;
	}
	if (keycode == 78) //minus
	{
		data->frct->xoff += (data->mx - (data->ww / 2)) / data->frct->zoomx;
		data->frct->yoff += (data->my - (data->wh / 2)) / data->frct->zoomy;
		data->frct->zoomy *= 0.75;
		data->frct->zoomx *= 0.75;
		if (data->zoomlevel != 0)
			data->zoomlevel--;
		data->frct->xoff -= (data->mx - (data->ww / 2)) / data->frct->zoomx;
		data->frct->yoff -= (data->my - (data->wh / 2)) / data->frct->zoomy;
	}
	if (keycode == 126)
		data->frct->yoff-= 14 / (data->frct->zoomy);
	if (keycode == 125)
		data->frct->yoff+= 14 / (data->frct->zoomy);
	if (keycode == 124)
		data->frct->xoff+= 14 / (data->frct->zoomx);
	if (keycode == 123)
		data->frct->xoff-= 14 / (data->frct->zoomx);
	if (keycode == 49)
		data->lock = data->lock ? 0 : 1;
	modify_image(data);
	return (1);
}

int	mouse_pos(int x, int y, t_f_data *d)
{
	ft_printf("x = %d, y = %d\n", x, y);
	if (!d->lock)
	{
		d->mxj = x;
		d->myj = y;
	}
	d->mx = x;
	d->my = y;
	modify_image(d);
	return(1);
}
