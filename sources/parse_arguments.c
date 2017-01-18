/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 14:24:58 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/20 14:57:18 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse_res(t_f_data *d, char *str)
{
	d->i2++;
	d->ww = ft_atoi(str + d->i2);
	d->i2 += ft_nbrlen(d->ww);
	if (str[d->i2] == 'x')
	{
		d->i2++;
		d->wh = ft_atoi(str + d->i2);
		d->i2 += ft_nbrlen(d->wh) - 1;
	}
	else
		return (d->errno = 8);
	d->mxj = d->ww / 2;
	d->myj = d->wh / 2;
	if (d->ww > 1200 || d->ww <= 16)
		return (d->errno = 10);
	if (d->wh > 1200 || d->wh <= 16)
		return (d->errno = 11);
	return (1);
}

int	parse_params(t_f_data *d, char *str)
{
	d->i2 = 0;
	while (str[d->i2])
	{
		d->i2 = str[d->i2] == '-' ? d->i2 + 1 : d->i2;
		d->errchar = str[d->i2];
		if (str[d->i2] == 'h')
			d->help = 1;
		else if (str[d->i2] == 'r')
		{
			if (parse_res(d, str) != 1)
				return (d->errno = d->errno);
		}
		else if (str[d->i2] == 't' && str[d->i2 + 1] &&
				ft_isdigit(str[d->i2 + 1]))
		{
			d->threads = ft_atoi(str + d->i2 + 1);
			if (d->threads > 16 || d->threads < 1)
				return (d->errno = 6);
			d->i2 += ft_nbrlen(d->threads);
		}
		else
			return (d->errno = 5);
		d->i2++;
	}
	return (0);
}

int	parse_arguments(t_f_data *d, int argc, char **argv)
{
	d->i = 1;
	if (argc <= 1)
		return (d->errno = 2);
	else
		while (d->i < argc)
		{
			if (argv[d->i][0] == '-')
			{
				if ((parse_params(d, argv[d->i])))
					return (d->errno = !d->errno ? 5 : d->errno);
			}
			else if (!(add_fractol_to_list(d, argv[d->i])))
				return (d->errno = 3);
			d->i++;
		}
	if (d->name == NULL)
		d->errno = 9;
	return (1);
}
