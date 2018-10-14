/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:24:16 by dbolilyi          #+#    #+#             */
/*   Updated: 2018/08/02 15:24:43 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_fract(t_mlx *iw)
{
	t_iw_func	funcs[8];

	funcs[0] = julia;
	funcs[1] = mandelbrot;
	funcs[2] = sierpinski_triangle;
	funcs[3] = burningship;
	funcs[4] = buffalo;
	funcs[5] = pyramid;
	funcs[6] = cock;
	funcs[7] = bigstar;
	iw->i = iw->st - 1;
	while (++iw->i < iw->end)
	{
		iw->j = -1;
		while (++iw->j < iw->winx)
			funcs[iw->v.frac_numb](iw);
	}
}

void	threads_fract(t_mlx *iw)
{
	pthread_t	threads[THREADS];
	t_mlx		iws[THREADS];
	int			i;
	int			j;

	if (iw->v.frac_numb != 2)
	{
		i = -1;
		j = 0;
		while (++i < THREADS)
		{
			iws[i] = *iw;
			iws[i].st = j;
			j += iw->winy / THREADS;
			iws[i].end = j;
			pthread_create(&threads[i], NULL,
					(void *(*)(void *))draw_fract, (void *)&iws[i]);
		}
		while (i-- > 0)
			iw->status = pthread_join(threads[i], (void **)&iws[i]);
	}
	else
		sierpinski_triangle(iw);
	mlx_put_image_to_window(iw->init, iw->win, iw->img_ptr, 0, 0);
}

void	update(t_mlx *iw, int *change, int pl)
{
	if (pl == 0)
		return ;
	if (change != 0)
		*change += pl;
	mlx_destroy_image(iw->init, iw->img_ptr);
	iw->img_ptr = mlx_new_image(iw->init, iw->winx, iw->winy);
	iw->img_data = mlx_get_data_addr(iw->img_ptr, &(iw->v.bpp),
			&(iw->v.size_line), &(iw->v.endian));
	mlx_clear_window(iw->init, iw->win);
	threads_fract(iw);
	mlx_put_image_to_window(iw->init, iw->win, iw->help_img_ptr, WINDOW_X, 0);
	draw_help_text(iw);
}

void	update2(t_mlx *iw, double *change, double pl)
{
	if (pl == 0)
		return ;
	if (change != 0)
		*change += pl;
	mlx_destroy_image(iw->init, iw->img_ptr);
	iw->img_ptr = mlx_new_image(iw->init, iw->winx, iw->winy);
	iw->img_data = mlx_get_data_addr(iw->img_ptr, &(iw->v.bpp),
			&(iw->v.size_line), &(iw->v.endian));
	mlx_clear_window(iw->init, iw->win);
	threads_fract(iw);
	mlx_put_image_to_window(iw->init, iw->win, iw->help_img_ptr, WINDOW_X, 0);
	draw_help_text(iw);
}

void	update3(t_mlx *iw, unsigned long long int *change,
		unsigned long long int pl)
{
	if (pl == 0)
		return ;
	if (change != 0)
		*change += pl;
	mlx_destroy_image(iw->init, iw->img_ptr);
	iw->img_ptr = mlx_new_image(iw->init, iw->winx, iw->winy);
	iw->img_data = mlx_get_data_addr(iw->img_ptr, &(iw->v.bpp),
			&(iw->v.size_line), &(iw->v.endian));
	mlx_clear_window(iw->init, iw->win);
	threads_fract(iw);
	mlx_put_image_to_window(iw->init, iw->win, iw->help_img_ptr, WINDOW_X, 0);
	draw_help_text(iw);
}
