/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 17:26:45 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/20 16:40:51 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*det_frct(void *data)
{
	t_tids		*t;
	t_f_data	*d;

	t = (t_tids *)data;
	d = t->data;
	if (!ft_strcmp("mandelbrot", d->name))
		mandelbrot(data);
	else if (!ft_strcmp("julia", d->name))
		julia(data);
	else if (!ft_strcmp("burningship", d->name))
		burning(data);
	else if (!ft_strcmp("gnome", d->name))
		gnome(data);
	else if (!ft_strcmp("moore", d->name))
		moore(data);
	pthread_exit(0);
}

static void	put_text(t_f_data *d)
{
	void	*w;

	w = d->window;
	mlx_string_put(d->init, w, 0, 0, WHITE, "index");
	mlx_string_put(d->init, w, 0, 16, WHITE, " name");
	mlx_string_put(d->init, w, 0, 32, WHITE, " iter");
	mlx_string_put(d->init, w, 0, 48, WHITE, "  red");
	mlx_string_put(d->init, w, 0, 64, WHITE, "green");
	mlx_string_put(d->init, w, 0, 80, WHITE, " blue");
	mlx_string_put(d->init, w, 0, 96, WHITE, "psych");
	mlx_string_put(d->init, w, 0, 112, WHITE, "mod i");
	mlx_string_put(d->init, w, 0, 126, WHITE, "mul i");
}

void		put_info(t_f_data *d)
{
	void	*w;

	w = d->window;
	mlx_string_put(d->init, w, 100, 0, WHITE, ft_itoa(d->currindex));
	mlx_string_put(d->init, w, 100, 16, WHITE, d->name);
	mlx_string_put(d->init, w, 100, 32, WHITE, ft_itoa(d->frct->iter));
	mlx_string_put(d->init, w, 100, 48, WHITE, ft_itoa(d->frct->color.r));
	mlx_string_put(d->init, w, 100, 64, WHITE, ft_itoa(d->frct->color.g));
	mlx_string_put(d->init, w, 100, 80, WHITE, ft_itoa(d->frct->color.b));
	mlx_string_put(d->init, w, 100, 96, WHITE, ft_itoa(d->woosh));
	mlx_string_put(d->init, w, 100, 112, WHITE, ft_itoa(d->frct->color.imax));
	mlx_string_put(d->init, w, 100, 126, WHITE, ft_itoa(d->frct->color.ntense));
	put_text(d);
}

void		modify_image(t_f_data *d)
{
	int		index;

	index = 0;
	d->threads = d->threads ? d->threads : 1;
	while (index < d->threads)
	{
		d->tids[index].index = index + 1;
		d->tids[index].data = (t_f_data *)d;
		pthread_create(&d->tids[index].thread, NULL,
				det_frct, (void *)&d->tids[index]);
		index++;
	}
	index = 0;
	while (index < d->threads)
		pthread_join((d->tids[index++].thread), NULL);
	mlx_put_image_to_window(d->init, d->window, d->image, 0, 0);
	put_info(d);
}
