/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 19:49:19 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/09 21:53:09 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_f_data	*init_data()
{
	t_f_data *data;

	if ((data = (t_f_data *)malloc(sizeof(t_f_data))) == NULL)
		return (NULL);
	data->drawrate = 1.20;
	data->name = NULL;
	data->init = NULL;
	data->window = NULL;
	data->zoomlevel = 1;
	data->ww = 500;
	data->wh = 500;
	data->image = NULL;
	data->istr = NULL;
	data->bpp = 0;
	data->sl = 0;
	data->endi = 0;
	data->errno = 0;
	data->errchar = 0;
	data->i = 0;
	data->i2 = 0;
	data->help = 0;
	data->threads = 0;
	data->togup = 0;
	data->mx = data->ww / 2;
	data->my = data->wh / 2;
	data->mxj = data->ww / 2;
	data->myj = data->wh / 2;
	data->mzoom = 0;
	data->lock = 1;
	data->woosh = 0;
	return (data);
}

t_f	*init_f()
{
	t_f	*new;

	if ((new = (t_f *)malloc(sizeof(t_f))) == NULL)
		return (NULL);
	new->zoomy = 100;
	new->zoomx = 100;
	new->iter = 10;
	new->xoff = 0;
	new->yoff = 0;
	new->c_r = -0.5;
	new->c_i = 0.5;
	new->z_r = 0;
	new->z_i = 0;
	new->i = 0;
	new->tmp = 0;
	new->tmp2 = 0;
	new->x = 0;
	new->y = 0;
	new->color.r = 255;
	new->color.g = 255;
	new->color.b = 255;

	return (new);
}

int		add_fractol_to_list(t_f_data *data, char *arg)
{
	int		count;

	count = 0;
	while (arg[count])
	{
		arg[count] = ft_tolower(arg[count]);
		count++;
	}
	if (!ft_strcmp("mandelbrot", arg))
	{
		data->name = ft_strnew(10);
		ft_strcpy(data->name, "mandelbrot");
	}
	else if (!ft_strcmp("julia", arg))
	{
		data->name = ft_strnew(5);
		ft_strcpy(data->name, "julia");
	}
	else if (!ft_strcmp("lederhose", arg))
	{
		data->name = ft_strnew(9);
		ft_strcpy(data->name, "lederhose");
	}
	else
	{
		data->name = ft_strnew(ft_strlen(arg));
		ft_strcpy(data->name, arg);
		return (0);
	}
	return (1);
}
