/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:47:45 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/20 16:54:35 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>
#include <time.h>
#include <stdio.h>

int		key_press_ext1(int keycode, t_f_data *d)
{
	if (keycode == KEY_BRACKETL)
	{
		if (d->currindex > 0)
			d->currindex--;
		else
			d->currindex = 4;
		d->name = d->validnames[d->currindex];
	}
	else if (keycode == KEY_BRACKETR)
	{
		if (d->currindex < 4)
			d->currindex++;
		else
			d->currindex = 0;
		d->name = d->validnames[d->currindex];
	}
	else if (keycode == KEY_W)
		d->wl = d->wl ? 0 : 1;
	else if (keycode == KEY_LEFT)
		d->frct->xoff -= 14 / (d->frct->zoomx);
	else
		return (0);
	return (1);
}

int		key_press(int keycode, t_f_data *d)
{
	if (key_press_ext1(keycode, d))
		d->lock = d->lock;
	else if (key_press_ext2(keycode, d))
		d->lock = d->lock;
	else if (key_press_ext3(keycode, d))
		d->lock = d->lock;
	else if (key_press_ext4(keycode, d))
		d->lock = d->lock;
	else if (key_press_ext5(keycode, d))
		d->lock = d->lock;
	else if (keycode == 49)
		d->lock = d->lock ? 0 : 1;
	if (d->lock == 0)
	{
		d->frct->xofflock = d->frct->xoff;
		d->frct->yofflock = d->frct->yoff;
		d->mxj = d->mx;
		d->myj = d->my;
		d->frct->zoomxlock = d->frct->zoomx;
		d->frct->zoomylock = d->frct->zoomy;
	}
	randomize_colors(d);
	modify_image(d);
	return (1);
}

int		mouse_pos(int x, int y, t_f_data *d)
{
	if (!d->lock && (!d->wl || (x >= 0 && y >= 0 && x <= d->ww && y <= d->wh)))
	{
		d->mxj = x;
		d->myj = y;
	}
	if (d->woosh)
		randomize_colors(d);
	d->mx = x;
	d->my = y;
	modify_image(d);
	return (1);
}

int		mouse_clickext1(int button, int x, int y, t_f_data *d)
{
	if (button == 4)
	{
		d->frct->xoff += (x - (d->ww / 2)) / d->frct->zoomx;
		d->frct->yoff += (y - (d->wh / 2)) / d->frct->zoomy;
		d->frct->zoomy *= 1.25;
		d->frct->zoomx *= 1.25;
		d->frct->xoff -= (x - (d->ww / 2)) / d->frct->zoomx;
		d->frct->yoff -= (y - (d->wh / 2)) / d->frct->zoomy;
		return (0);
	}
	else
		return (0);
	return (1);
}

int		mouse_click(int button, int x, int y, t_f_data *d)
{
	if (!mouse_clickext1(button, x, y, d))
	{
		if (button == 3)
		{
			d->frct->xoff += (x - (d->ww / 2)) / d->frct->zoomx;
			d->frct->yoff += (y - (d->wh / 2)) / d->frct->zoomy;
			d->frct->zoomy *= 0.75;
			d->frct->zoomx *= 0.75;
			d->frct->xoff -= (x - (d->ww / 2)) / d->frct->zoomx;
			d->frct->yoff -= (y - (d->wh / 2)) / d->frct->zoomy;
		}
	}
	if (!d->lock)
	{
		d->frct->zoomxlock = d->frct->zoomx;
		d->frct->zoomylock = d->frct->zoomy;
		d->frct->yofflock = d->frct->yoff;
		d->frct->xofflock = d->frct->xoff;
	}
	modify_image(d);
	return (1);
}
