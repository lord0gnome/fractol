/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:45:41 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/09 21:55:53 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include "printf/ft_printf.h"
#include "libft/libft.h"
#include "mlx.h"
#include "X.h"
#include "keys.h"
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

typedef struct	s_tids
{
	void	*data;
	int		index;
	pthread_t	thread;
}				t_tids;

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	rb;
	unsigned char	gb;
	unsigned char	bb;
	unsigned char	rup;
	unsigned char	gup;
	unsigned char	bup;
	unsigned char	rr;
	unsigned char	gr;
	unsigned char	br;
	unsigned char	ntense;
	unsigned char	ntup;
	unsigned char	imax;

}				t_color;

typedef struct	s_f_data
{
	char		lock;
	size_t	zoomlevel;
	struct s_f	*frct;
	int			i;
	char		togup;
	float		drawrate;
	int			i2;
	char		*name;
	void		*init;
	void		*window;
	int			ww;
	int			wh;
	void		*image;
	char		*istr;
	int			bpp;
	int			sl;
	int			endi;
	int			errno;
	char		errchar;
	char		help;
	int			threads;
	struct s_tids tids[9];
	int		mx;
	int		my;
	int		mxj;
	int		myj;
	char		mzoom;
	char		woosh;
}				t_f_data;

typedef struct			s_f
{
	char			*name;
	double			xoff;
	double			yoff;
	double			zoomx;
	double			zoomy;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			i;
	double			tmp;
	double			tmp2;
	int				len;
	int				iter;
	int				x;
	int				y;
	struct s_color	color;
}						t_f;

t_color	set_color_ntense(int n, t_color c);
t_color	invert_colors(t_color c);
t_color	init_color(t_color c);
t_color	det_color(t_color c, int i);
void	*mandelbrot(void *data);
t_f_data	*init_data();
void	print_options(t_f_data *data);
int		parse_arguments(t_f_data *data, int argc, char **argv);
int		add_fractol_to_list(t_f_data *data, char *arg);
void	do_fractals(t_f_data *data);
int		key_press(int keycode, t_f_data *data);
int		mouse_pos(int x, int y, t_f_data *d);
t_f		*init_f(void);
void	modify_image(t_f_data *data);
void	ft_putpixel(int x, int y, int c, t_f_data *d);
void	draw_pixel(t_f_data *data);
void	ft_putpixel_frct(int x, int y, t_color c, t_f_data *d);

# endif
