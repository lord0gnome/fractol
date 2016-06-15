/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:47:45 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/15 15:02:45 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>
#include <time.h>
#include <stdio.h>
int	key_press(int keycode, t_f_data *data)
{
	if (keycode == KEY_BRACKETL)
	{
		if (data->currindex > 0)
			data->currindex--;
		else
			data->currindex = 2;
		data->name = data->validnames[data->currindex];
	}
	else if (keycode == KEY_BRACKETR)
	{
		if (data->currindex < 2)
			data->currindex++;
		else
			data->currindex = 0;
		data->name = data->validnames[data->currindex];
	}
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
	if (keycode == KEY_DOT && data->frct->color.imax < 20)
		data->frct->color.imax++;
	if (keycode == KEY_COMMA && data->frct->color.imax > 1)
		data->frct->color.imax--;
	if (keycode == KEY_1)
	{
		data->frct->color.ntense = 1;
		data->frct->color.imax = 1;
	}
	if (keycode == KEY_TILT)
		data->woosh = data->woosh ? 0 : 1;
	if (keycode == KEY_R)
	{
		data->frct->zoomx = 100;
		data->frct->zoomy = 100;
		data->frct->xoff = 0;
		data->frct->yoff = 0;
	}
	if (keycode == 27 && data->frct->iter > 1)
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
	}
	if (keycode == 78) //minus
	{
		data->frct->xoff += (data->mx - (data->ww / 2)) / data->frct->zoomx;
		data->frct->yoff += (data->my - (data->wh / 2)) / data->frct->zoomy;
		data->frct->zoomy *= 0.75;
		data->frct->zoomx *= 0.75;
		data->frct->xoff -= (data->mx - (data->ww / 2)) / data->frct->zoomx;
		data->frct->yoff -= (data->my - (data->wh / 2)) / data->frct->zoomy;
	}
	if (keycode == KEY_B)
	{
		data->frct->color.r = 0;
		data->frct->color.g = 0;
		data->frct->color.b = 0;
		data->frct->color.rb = 0;
		data->frct->color.gb = 0;
		data->frct->color.bb = 0;
	}
	if (keycode == KEY_T)
		data->frct->zoomy *= 1.25;
	if (keycode == KEY_F)
		data->frct->zoomx *= 0.75;
	if (keycode == KEY_G)
		data->frct->zoomy *= 0.75;
	if (keycode == KEY_H)
		data->frct->zoomx *= 1.25;
	if (keycode == KEY_N)
		data->crazy = data->crazy ? 0 : 1;
	if (keycode == 126)
		data->frct->yoff-= 14 / (data->frct->zoomy);
	if (keycode == 125)
		data->frct->yoff+= 14 / (data->frct->zoomy);
	if (keycode == 124)
		data->frct->xoff+= 14 / (data->frct->zoomx);
	if (keycode == 123)
		data->frct->xoff-= 14 / (data->frct->zoomx);
	if (keycode == 49)
	{
		data->lock = data->lock ? 0 : 1;
	}
	if (data->lock == 0)
	{
		data->frct->xofflock = data->frct->xoff;
		data->frct->yofflock = data->frct->yoff;
		data->mxj = data->mx;
		data->myj = data->my;
		data->frct->zoomxlock = data->frct->zoomx;
		data->frct->zoomylock = data->frct->zoomy;
	}
	randomize_colors(data);
	modify_image(data);
	return (1);
}

int	mouse_pos(int x, int y, t_f_data *d)
{
	if (!d->lock)
	{
		d->mxj = x;
		d->myj = y;
	}
	if (d->woosh)
		randomize_colors(d);
	d->mx = x;
	d->my = y;
	modify_image(d);
	return(1);
}

int	mouse_click(int button, int x, int y, t_f_data *data)
{
	if (button == 4) /*mwheelup*/
	{
		data->frct->xoff += (x - (data->ww / 2)) / data->frct->zoomx;
		data->frct->yoff += (y - (data->wh / 2)) / data->frct->zoomy;
		data->frct->zoomy *= 1.25;
		data->frct->zoomx *= 1.25;
		data->frct->xoff -= (x - (data->ww / 2)) / data->frct->zoomx;
		data->frct->yoff -= (y - (data->wh / 2)) / data->frct->zoomy;
	}
	if (button == 3) /*mwheeldown*/
	{
		data->frct->xoff += (x - (data->ww / 2)) / data->frct->zoomx;
		data->frct->yoff += (y - (data->wh / 2)) / data->frct->zoomy;
		data->frct->zoomy *= 0.75;
		data->frct->zoomx *= 0.75;
		data->frct->xoff -= (x - (data->ww / 2)) / data->frct->zoomx;
		data->frct->yoff -= (y - (data->wh / 2)) / data->frct->zoomy;
	}
	if (!data->lock)
	{
		data->frct->zoomxlock = data->frct->zoomx;
		data->frct->zoomylock = data->frct->zoomy;
		data->frct->yofflock = data->frct->yoff;
		data->frct->xofflock = data->frct->xoff;
	}
	modify_image(data);
	return (1);
}
