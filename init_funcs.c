/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 19:49:19 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/20 16:53:32 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_f_data	*init_data_ext(t_f_data *data)
{
	data->init = NULL;
	data->window = NULL;
	data->image = NULL;
	data->istr = NULL;
	data->mzoom = 0;
	data->togup = 0;
	data->lock = 1;
	data->help = 0;
	data->errchar = 0;
	data->errname = NULL;
	data->i = 0;
	data->i2 = 0;
	data->bpp = 0;
	data->sl = 0;
	data->endi = 0;
	data->errno = 0;
	data->threads = 0;
	data->ww = 500;
	data->wh = 500;
	data->mx = data->ww / 2;
	data->my = data->wh / 2;
	data->mxj = data->mx;
	data->myj = data->my;
	return (data);
}

t_f_data	*init_data(void)
{
	t_f_data *data;

	if ((data = (t_f_data *)malloc(sizeof(t_f_data))) == NULL)
		return (NULL);
	data = init_data_ext(data);
	data->name = NULL;
	data->crazy = 1;
	data->woosh = 0;
	data->wl = 1;
	if (!(data->validnames = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	data->validnames[0] = ft_strnew(10);
	ft_strcpy(data->validnames[0], "mandelbrot");
	data->validnames[1] = ft_strnew(5);
	ft_strcpy(data->validnames[1], "julia");
	data->validnames[2] = ft_strnew(11);
	ft_strcpy(data->validnames[2], "burningship");
	data->validnames[3] = ft_strnew(5);
	ft_strcpy(data->validnames[3], "gnome");
	data->validnames[4] = ft_strnew(5);
	ft_strcpy(data->validnames[4], "moore");
	data->currindex = 0;
	return (data);
}

t_f			*init_f(void)
{
	t_f	*new;

	if ((new = (t_f *)malloc(sizeof(t_f))) == NULL)
		return (NULL);
	new->zoomy = 100;
	new->zoomx = 100;
	new->zoomylock = 100;
	new->zoomxlock = 100;
	new->iter = 10;
	new->xoff = 0;
	new->yoff = 0;
	new->xofflock = 0;
	new->yofflock = 0;
	new->c_r = -0.5;
	new->c_i = 0.5;
	new->z_r = 0;
	new->z_i = 0;
	new->i = 0;
	new->tmp = 0;
	new->tmp2 = 0;
	new->x = 0;
	new->y = 0;
	return (new);
}

int			add_fractol_to_list(t_f_data *data, char *arg)
{
	data->i = 0;
	data->i2 = 0;
	while (arg[data->i])
	{
		arg[data->i] = ft_tolower(arg[data->i]);
		data->i++;
	}
	data->vnindex = 0;
	while (data->validnames[data->vnindex] && data->vnindex < 6)
	{
		if (!ft_strcmp(data->validnames[data->vnindex], arg))
		{
			data->name = ft_strnew(ft_strlen(data->validnames[data->vnindex]));
			ft_strcpy(data->name, data->validnames[data->vnindex]);
			data->i2 = 1;
			data->currindex = data->vnindex;
		}
		if (data->i != 0)
		{
			data->errname = ft_strnew(ft_strlen(arg));
			ft_strcpy(data->errname, arg);
		}
		data->vnindex++;
	}
	return (data->i2);
}
