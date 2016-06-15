/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:56:09 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/15 15:03:26 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_more_options(t_f_data *data)
{
	if (data->errno == 2)
		ft_putstr("Not enough arguments supplied. Correct format below.\n");
	else if (data->errno == 3)
	{
		ft_putstr("Invalid fractal supplied on argument \"");
		ft_putstr(data->errname);
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
		ft_putstr("Too many or too few threads. pick a number between 1-16\n");
	else if (data->errno == 9)
		ft_putstr("No fractal supplied\n");
	else if (data->errno == 10)
		ft_putstr("Chosen width too high.\n");
	else if (data->errno == 11)
		ft_putstr("Chosen height too high.\n");
}

void	print_options(t_f_data *data)
{
	if (data->errno != 0 && data->errno != -1)
		ft_putstr("ERROR : ");
	print_more_options(data);
	if (data->errno != -1 && (data->errno != 0 ||
		data->errno == 5 || data->errno == 3))
	{
		ft_putstr("ARGS -tN -rNxN -h where N == (INT)\n");
		ft_putstr("	-tN determines the max threads\n");
		ft_putstr("	-rNxN determines the size of window, width x height\n");
		ft_putstr("	-h prints useful information\n");
		ft_putstr("USAGE -ARGS ./fractol julia/mandelbrot/burningship\n");
	}
	if (data->help)
	{
		ft_putstr("\nHELP\n");
		ft_putstr("\nHELP\n\n");
	}
	if (data->errno == -1)
	{
		exit(EXIT_SUCCESS);
	}
	if (!data->errno)
		return ;
	exit(EXIT_FAILURE);
}
