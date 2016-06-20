/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 16:20:00 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/20 16:53:53 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press_ext5(int keycode, t_f_data *d)
{
	if (keycode == KEY_DOWN)
		d->frct->yoff += 14 / (d->frct->zoomy);
	else if (keycode == KEY_RIGHT)
		d->frct->xoff += 14 / (d->frct->zoomx);
	else if (keycode == KEY_L)
		d->frct->color = set_color_ntense(1, d->frct->color);
	else if (keycode == KEY_K)
		d->frct->color = set_color_ntense(-1, d->frct->color);
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_image(d->init, d->image);
		mlx_destroy_window(d->init, d->window);
		d->errno = -1;
		print_options(d);
	}
	else if (keycode == KEY_C)
		d->frct->color = init_color(d->frct->color);
	else
		return (0);
	return (1);
}

int		key_press_ext4(int keycode, t_f_data *d)
{
	if (keycode == KEY_B)
	{
		d->frct->color.r = 0;
		d->frct->color.g = 0;
		d->frct->color.b = 0;
		d->frct->color.rb = 0;
		d->frct->color.gb = 0;
		d->frct->color.bb = 0;
	}
	else if (keycode == KEY_T)
		d->frct->zoomy *= 1.1;
	else if (keycode == KEY_F)
		d->frct->zoomx *= 0.9;
	else if (keycode == KEY_G)
		d->frct->zoomy *= 0.9;
	else if (keycode == KEY_H)
		d->frct->zoomx *= 1.1;
	else if (keycode == KEY_N)
		d->crazy = d->crazy ? 0 : 1;
	else if (keycode == KEY_UP)
		d->frct->yoff -= 14 / (d->frct->zoomy);
	else
		return (0);
	return (1);
}

int		key_press_ext3(int keycode, t_f_data *d)
{
	if (keycode == KEY_MINUS && d->frct->iter > 1)
		d->frct->iter--;
	else if (keycode == KEY_EQUAL)
		d->frct->iter++;
	else if (keycode == 69)
	{
		d->frct->xoff += (d->mx - (d->ww / 2)) / d->frct->zoomx;
		d->frct->yoff += (d->my - (d->wh / 2)) / d->frct->zoomy;
		d->frct->zoomy *= 1.25;
		d->frct->zoomx *= 1.25;
		d->frct->xoff -= (d->mx - (d->ww / 2)) / d->frct->zoomx;
		d->frct->yoff -= (d->my - (d->wh / 2)) / d->frct->zoomy;
	}
	else if (keycode == 78)
	{
		d->frct->xoff += (d->mx - (d->ww / 2)) / d->frct->zoomx;
		d->frct->yoff += (d->my - (d->wh / 2)) / d->frct->zoomy;
		d->frct->zoomy *= 0.75;
		d->frct->zoomx *= 0.75;
		d->frct->xoff -= (d->mx - (d->ww / 2)) / d->frct->zoomx;
		d->frct->yoff -= (d->my - (d->wh / 2)) / d->frct->zoomy;
	}
	else
		return (0);
	return (1);
}

int		key_press_ext2(int keycode, t_f_data *d)
{
	if (keycode == KEY_DOT && d->frct->color.imax < 20)
		d->frct->color.imax++;
	else if (keycode == KEY_COMMA && d->frct->color.imax > 1)
		d->frct->color.imax--;
	else if (keycode == KEY_1)
	{
		d->frct->color.ntense = 1;
		d->frct->color.imax = 1;
	}
	else if (keycode == KEY_TILT)
		d->woosh = d->woosh ? 0 : 1;
	else if (keycode == KEY_R)
	{
		d->frct->zoomx = 100;
		d->frct->zoomy = 100;
		d->frct->xoff = 0;
		d->frct->yoff = 0;
	}
	else if (keycode == KEY_I)
		d->frct->color = invert_colors(d->frct->color);
	else
		return (0);
	return (1);
}
