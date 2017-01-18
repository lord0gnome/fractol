/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:21:15 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/15 14:05:57 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putpixel_frct(int x, int y, t_color c, t_f_data *d)
{
	if (d->endi)
	{
		(d->istr)[((y * d->sl) + (x * (d->bpp / 8)))] = c.r;
		(d->istr)[((y * d->sl) + (x * (d->bpp / 8))) + 1] = c.g;
		(d->istr)[((y * d->sl) + (x * (d->bpp / 8))) + 2] = c.b;
	}
	else
	{
		(d->istr)[((y * d->sl) + (x * (d->bpp / 8))) + 2] = c.r;
		(d->istr)[((y * d->sl) + (x * (d->bpp / 8))) + 1] = c.g;
		(d->istr)[((y * d->sl) + (x * (d->bpp / 8)))] = c.b;
	}
}
