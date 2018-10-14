/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 13:58:11 by dbolilyi          #+#    #+#             */
/*   Updated: 2018/08/02 16:28:55 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <math.h>
# include <pthread.h>

# define WINDOW_X 1500
# define WINDOW_Y 1300
# define THREADS 5

# define INWIWIN iw->init, iw->win, WINDOW_X

typedef struct	s_mand
{
	double	zx;
	double	zy;
	double	xtemp;
	double	x;
	double	y;
	int		iter;
}				t_mand;

typedef struct	s_view
{
	int						frac_numb;
	int						pause;
	double					x;
	double					y;
	int						max_iter;
	unsigned long long int	scale;
	double					cre;
	double					cim;
	int						chng_color;
	int						standart_color;
	int						bpp;
	int						size_line;
	int						endian;
}				t_view;

typedef struct	s_sier
{
	int				points[3][2];
	int				rot;
	int				rot_change;
	int				angle;
	struct s_mlx	*iw;
}				t_sier;

typedef struct	s_mlx
{
	int			winx;
	int			winy;
	int			pixel_plus;
	void		*init;
	void		*win;
	void		*img_ptr;
	char		*img_data;
	void		*help_img_ptr;
	int			st;
	int			end;
	int			status;
	int			*img_status_addr;
	int			i;
	int			j;
	t_view		v;
	t_sier		s;
}				t_mlx;

typedef void	(*t_iw_func) (t_mlx * iw);

typedef struct	s_brez
{
	int			x;
	int			y;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			k;
	int			color;
	t_mlx		*iw;
}				t_brez;

typedef struct	s_draw_line
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_draw_line;

void			pixel_put_img(t_mlx *iw, int x, int y, int color);
void			print_brez(t_brez *b, int d, int d1, int d2);
void			brez_line(t_mlx *iw, t_draw_line line, int color);
void			julia(t_mlx *iw);
void			buffalo(t_mlx *iw);
void			cock(t_mlx *iw);
void			burningship(t_mlx *iw);
void			pyramid(t_mlx *iw);
void			bigstar(t_mlx *iw);
void			mandelbrot(t_mlx *iw);
void			drawtriangle(t_mlx *iw, int points[3][2]);
void			get_tr_coord(int points[3][2], int radius, int angle, int rot);
void			sierpinski(t_sier *s, int radius, int angle, int iter);
void			sierpinski_triangle(t_mlx *iw);
void			draw_fract(t_mlx *iw);
void			draw_help_fract2(t_mlx *iw);
void			draw_help_fract(t_mlx *iw);
void			draw_help_colors(t_mlx *iw);
void			threads_fract(t_mlx *iw);
void			draw_help_text2(t_mlx *iw);
void			draw_help_text(t_mlx *iw);
void			update(t_mlx *iw, int *change, int pl);
void			update2(t_mlx *iw, double *change, double pl);
void			update3(t_mlx *iw, unsigned long long int *change,
		unsigned long long int pl);
int				key_hook2(int keycode, t_mlx *iw);
int				key_hook(int keycode, t_mlx *iw);
int				mouse_move(int x, int y, t_mlx *iw);
void			reset_view(t_mlx *iw);
void			switch_color(int x, int y, t_mlx *iw);
void			switch_frac2(t_mlx *iw, int numb);
void			switch_frac(int x, int y, t_mlx *iw);
void			mouse_hook2(int button, t_mlx *iw);
int				mouse_hook(int button, int x, int y, t_mlx *iw);
void			draw_help_lines2(t_mlx *iw, t_draw_line *line);
void			draw_help_lines(t_mlx *iw);
void			get_help_img(t_mlx *iw);
int				choose_fractal2(t_mlx *iw, char **argv);
int				choose_fractal(t_mlx *iw, int argc, char **argv);
void			set_defaultview(t_mlx *iw);
#endif
