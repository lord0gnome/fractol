/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 19:49:19 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/11 17:46:15 by guiricha         ###   ########.fr       */
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
	data->errname = NULL;
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
	data->mxj = data->mx;
	data->myj = data->my;
	data->mzoom = 0;
	data->lock = 1;
	data->woosh = 0;
	data->crazy = 1;
	if (!(data->validnames = (char **)malloc(sizeof(char *) * 3)))
		return (NULL);
	data->validnames[0] = ft_strnew(10);
	ft_strcpy(data->validnames[0], "mandelbrot");
	data->validnames[1] = ft_strnew(5);
	ft_strcpy(data->validnames[1], "julia");
	data->validnames[2] = ft_strnew(11);
	ft_strcpy(data->validnames[2], "burningship");
	data->currindex = 0;
	return (data);
}

t_f	*init_f()
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
	new->color.r = 255;
	new->color.g = 255;
	new->color.b = 255;

	return (new);
}

int		add_fractol_to_list(t_f_data *data, char *arg)
{
	int		count;
	int		currvalid;

	count = 0;
	currvalid = 0;
	while (arg[count])
	{
		arg[count] = ft_tolower(arg[count]);
		count++;
	}
	data->validnamesi = 0;
	while (data->validnames[data->validnamesi] && data->validnamesi < 3)
	{
		if (!ft_strcmp(data->validnames[data->validnamesi], arg))
		{
			data->name = ft_strnew(ft_strlen(data->validnames[data->validnamesi]));
			ft_strcpy(data->name, data->validnames[data->validnamesi]);
			currvalid = 1;
			data->currindex = data->validnamesi;
		}
		if (count != 0)
		{
		data->errname = ft_strnew(ft_strlen(arg));
		ft_strcpy(data->errname, arg);
		}
		data->validnamesi++;
	}
	return (currvalid);
}

t_f		init_mandelbrot(t_f f, t_f_data *d)
{
	f.c_r = (f.x - (d->ww/2)) / f.zoomx + f.xoff;
	f.c_i = (f.y - (d->wh/2)) / f.zoomy + f.yoff;
	f.z_r = 0;
	f.z_i = 0;
	f.i = 0;
	return (f);
}

t_f		init_julia(t_f f, t_f_data *d)
{
	f.c_r = (d->mxj - d->ww / 2) / (f.zoomxlock) + f.xofflock;
	f.c_i = (d->myj - d->wh / 2) / (f.zoomylock) + f.yofflock;
	f.z_r = (f.x - d->ww / 2) / (f.zoomx) + f.xoff;
	f.z_i = (f.y - d->wh / 2) / (f.zoomy) + f.yoff;
	f.i = 0;
	return (f);
}
t_f		init_newton(t_f f, t_f_data *d)
{
	f.c_r = (f.x - (d->ww/2)) / f.zoomx + f.xoff;
	f.c_i = (f.y - (d->wh/2)) / f.zoomy + f.yoff;
	f.z_r = 0;
	f.z_i = 0;
	f.i = 0;
	return (f);
}
