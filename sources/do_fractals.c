/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fractals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:36:28 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/20 12:45:57 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		randomize_colors(t_f_data *d)
{
	if (d->woosh)
	{
		if (d->frct->color.ntense > 25)
			d->frct->color.ntup = 0;
		else if (d->frct->color.ntense <= 2)
			d->frct->color.ntup = 1;
		d->frct->color.ntense += d->frct->color.ntup ? 1 : -1;
		modify_image(d);
	}
	return (1);
}

void	do_fractals(t_f_data *data)
{
	modify_image(data);
	mlx_loop_hook(data->init, &randomize_colors, data);
	mlx_hook(data->window, MotionNotify, PointerMotionMask, &mouse_pos, data);
	mlx_hook(data->window, KeyPress, KeyPressMask, &key_press, data);
	mlx_mouse_hook(data->window, &mouse_click, data);
	mlx_loop(data->init);
}
