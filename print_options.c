/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:56:09 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/05 18:56:32 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_options(t_f_data *data)
{
	if (data->errno == 2)
		ft_putstr("Not enough arguments supplied. Correct format below.\n");
	else if (data->errno == 3)
	{
		ft_putstr("Invalid fractal supplied on argument \"");
		ft_putstr(data->name);
		ft_putstr("\" Correct format below.\n");
	}
	else if (data->errno == 4)
		ft_putstr("Malloc error, try again\n");
	else if (data->errno == 5)
	{
		ft_putstr("Unknown argument \'");
		ft_putchar(data->errchar);
		ft_putstr("\' supplied. Correct format below.\n");
	}
	else if (data->errno == 6)
		ft_putstr("Too many or too few threads. pick a number between 1 and 9\n");
	if (data->errno != 5 && data->errno != 0 && data->errno != -1)
		ft_putstr("USAGE	./fractol julia/mandelbrot\n");
	if (data->errno == 2 || data->errno == 5 || data->errno == 3)
		ft_putstr("ARGS	./fractol -tNh\n");
	if (data->help)
	{
		ft_putstr("Fill this with useful information for the user!!!\n");
	}
	if (data->errno == -1)
	{
		exit(EXIT_SUCCESS);
	}
	if (!data->errno)
		return ;
	exit(EXIT_FAILURE);
}
