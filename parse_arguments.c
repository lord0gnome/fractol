/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 14:24:58 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/07 20:02:18 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse_params(t_f_data *data, char *str)
{
	data->i2 = 0;
	while (str[data->i2])
	{
		ft_putchar(str[data->i2]);
		if (str[data->i2] == '-')
			data->i2++;
		if (str[data->i2] == 'h')
			data->help = 1;
		else if (str[data->i2] == 'r')
		{
			data->i2++;
			data->ww = ft_atoi(str + data->i2);	
			data->i2 += ft_nbrlen(data->ww);
			if (str[data->i2] == 'x' || str[data->i2] == '*')
			{
			data->i2++;
			data->wh = ft_atoi(str + data->i2);
			data->i2 += ft_nbrlen(data->wh) - 1;
			}
			else
			{
				data->errno = 8;
				return (0);
			}
			data->mxj = data->ww/2;
			data->myj = data->wh/2;
		}
		else if (str[data->i2] == 't' && str[data->i2 + 1] && ft_isdigit(str[data->i2 + 1]))
		{
			data->threads = ft_atoi(str + data->i2 + 1);
			if (data->threads > 9 || data->threads < 1)
			{
				data->errno = 6;
				return (0);
			}
			data->i2++;
		}
		else
		{
			data->errchar = str[data->i2];
			data->errno = 5;
			return (0);
		}
		data->i2++;
	}
	return (1);
}

int	parse_arguments(t_f_data *data, int argc, char **argv)
{
	data->i = 1;
	if (argc <= 1)
	{
		data->errno = 2;
		return (-1);
	}
	else
		while(data->i < argc)
		{
			if (argv[data->i][0] == '-')
			{
				if (!(parse_params(data, argv[data->i])))
				{
					data->errno = !data->errno ? 5 : data->errno;
					return (-1);
				}
			}
			else if (!(add_fractol_to_list(data, argv[data->i])))
			{
				data->errno = 3;
				return (-1);
			}
			data->i++;
		}
	return (1);
}
