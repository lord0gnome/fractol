/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:45:29 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/09 22:16:25 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_f_data	*d;
	t_f			*f;

	d = init_data();
	parse_arguments(d, argc, argv);
	if (d->errno)
		print_options(d);
	srand(time(NULL));
	f = init_f();
	d->frct = f;
	f->color = init_color(f->color);
	f->color.imax = 1;
	d->init = mlx_init();
	d->window = mlx_new_window(d->init, d->ww, d->wh - 8, d->name);
	d->image = mlx_new_image(d->init, d->ww, d->wh);
	d->istr = mlx_get_data_addr(d->image, &d->bpp, &d->sl, &d->endi);
	do_fractals(d);
	print_options(d);
	return (0);
}
