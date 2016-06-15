/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:45:41 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/15 16:29:01 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "printf/ft_printf.h"
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "minilibx_macos/X.h"
# include "keys.h"
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include <time.h>

typedef struct		s_tids
{
	void			*data;
	int				index;
	pthread_t		thread;
}					t_tids;

typedef struct		s_color
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

}					t_color;

typedef struct		s_f_data
{
	void			*init;
	void			*window;
	void			*image;
	char			*istr;
	char			mzoom;
	char			woosh;
	char			crazy;
	char			togup;
	char			lock;
	char			help;
	char			errchar;
	char			*name;
	char			*errname;
	char			**validnames;
	int				vnindex;
	int				currindex;
	int				i;
	int				i2;
	int				bpp;
	int				sl;
	int				endi;
	int				errno;
	int				threads;
	int				ww;
	int				wh;
	int				mx;
	int				my;
	int				mxj;
	int				myj;
	struct s_f		*frct;
	struct s_tids	tids[16];
}					t_f_data;

typedef struct		s_f
{
	char			*name;
	double			angle;
	double			ca;
	double			sa;
	double			r;
	double			xoff;
	double			yoff;
	double			xofflock;
	double			yofflock;
	double			zoomx;
	double			zoomy;
	double			zoomxlock;
	double			zoomylock;
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
}					t_f;

void				show_fps(t_f_data *d);
t_f					*init_f(void);
t_f_data			*init_data();
t_f					init_mandelbrot(t_f f, t_f_data *d);
t_f					init_julia(t_f f, t_f_data *d);
t_f					init_newton(t_f f, t_f_data *d);
int					randomize_colors(t_f_data *d);
t_color				boring_color(t_color c, int i, int imax);
t_color				set_color_ntense(int n, t_color c);
t_color				invert_colors(t_color c);
t_color				init_color(t_color c);
t_color				det_color(t_color c, int new, int new2);
void				*mandelbrot(void *data);
void				*julia(void *data);
void				*burning(void *data);
void				print_options(t_f_data *data);
int					parse_arguments(t_f_data *data, int argc, char **argv);
int					add_fractol_to_list(t_f_data *data, char *arg);
int					key_press(int keycode, t_f_data *d);
int					mouse_pos(int x, int y, t_f_data *d);
int					mouse_click(int button, int x, int y, t_f_data *d);
void				ft_putpixel(int x, int y, int c, t_f_data *d);
void				draw_pixel(t_f_data *data);
void				ft_putpixel_frct(int x, int y, t_color c, t_f_data *d);
void				modify_image(t_f_data *data);
void				do_fractals(t_f_data *data);

#endif
