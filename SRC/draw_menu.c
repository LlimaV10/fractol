/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:24:20 by dbolilyi          #+#    #+#             */
/*   Updated: 2018/08/02 15:24:21 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_help_fract2(t_mlx *iw)
{
	t_iw_func	funcs[5];
	int			i;

	funcs[0] = burningship;
	funcs[1] = buffalo;
	funcs[2] = pyramid;
	funcs[3] = cock;
	funcs[4] = bigstar;
	iw->winx = 40;
	iw->winy = 40;
	i = -1;
	while (++i < 5)
	{
		iw->pixel_plus = i * 40;
		iw->i = -1;
		while (++iw->i < iw->winy)
		{
			iw->j = -1;
			while (++iw->j < iw->winx)
				funcs[i](iw);
			iw->pixel_plus += 160;
		}
	}
	iw->pixel_plus = 0;
}

void	draw_help_fract(t_mlx *iw)
{
	iw->v.x = 0;
	iw->i = -1;
	while (++iw->i < 200)
	{
		iw->j = -1;
		while (++iw->j < 200)
			julia(iw);
	}
	iw->img_data += iw->winx * iw->winy * sizeof(int);
	iw->i = -1;
	while (++iw->i < 200)
	{
		iw->j = -1;
		while (++iw->j < 200)
			mandelbrot(iw);
	}
	iw->img_data += iw->winx * iw->winy * sizeof(int);
	sierpinski_triangle(iw);
	iw->img_data += iw->winx * (iw->winy - 50) * sizeof(int);
	draw_help_fract2(iw);
	iw->winx = 200;
	iw->winy = 200;
}

void	draw_help_colors(t_mlx *iw)
{
	int		*tmp;

	iw->i = -1;
	iw->img_data += iw->winx * sizeof(int) * (WINDOW_Y - (int)(2.75 *
				(float)iw->winy));
	tmp = (int *)iw->img_data;
	while (++iw->i < iw->winx / 4)
	{
		iw->j = -1;
		while (++iw->j < iw->winx / 4)
			*(tmp--) = 0x00DB26;
		iw->j = -1;
		while (++iw->j < iw->winx / 4)
			*(tmp--) = 0xDF00C4;
		iw->j = -1;
		while (++iw->j < iw->winx / 4)
			*(tmp--) = 0x003DA2;
		iw->j = -1;
		while (++iw->j < iw->winx / 4)
			*(tmp--) = 0xFF8600;
	}
}

void	draw_help_text2(t_mlx *iw)
{
	mlx_string_put(INWIWIN + 30, 797, 0xFFFFFF, "to change colors");
	mlx_string_put(INWIWIN + 10, 825, 0x00FF00, "SPACE");
	mlx_string_put(INWIWIN + 10, 825, 0xFFFFFF, "      to pause");
	mlx_string_put(INWIWIN + 10, 850, 0x00FF00, "LEFT MB");
	mlx_string_put(INWIWIN + 10, 850, 0xFFFFFF, "        to move");
	mlx_string_put(INWIWIN + 10, 870, 0xFFFFFF, "where the mouse");
	mlx_string_put(INWIWIN + 10, 890, 0xFFFFFF, "is pressed to the");
	mlx_string_put(INWIWIN + 10, 910, 0xFFFFFF, "center");
	mlx_string_put(INWIWIN + 10, 930, 0x00FF00, "MOVE MOUSE");
	mlx_string_put(INWIWIN + 10, 930, 0xFFFFFF, "           to");
	mlx_string_put(INWIWIN + 10, 950, 0xFFFFFF, "change parameters");
	mlx_string_put(INWIWIN + 10, 970, 0xFFFFFF, "of the fractols");
	mlx_string_put(INWIWIN + 10, 990, 0x00FF00, "MOUSE WHEEL");
	mlx_string_put(INWIWIN + 10, 990, 0xFFFFFF, "            to");
	mlx_string_put(INWIWIN + 10, 1010, 0xFFFFFF, "zoom");
}

void	draw_help_text(t_mlx *iw)
{
	mlx_string_put(INWIWIN + 30, 630, 0xFFFFFF, "Press:");
	mlx_string_put(INWIWIN + 10, 650, 0x00FF00, "+");
	mlx_string_put(INWIWIN + 10, 650, 0xFFFFFF, "  to increase");
	mlx_string_put(INWIWIN + 30, 670, 0xFFFFFF, "iterations");
	mlx_string_put(INWIWIN + 10, 690, 0x00FF00, "-");
	mlx_string_put(INWIWIN + 10, 690, 0xFFFFFF, "  to decrease");
	mlx_string_put(INWIWIN + 30, 710, 0xFFFFFF, "iterations");
	mlx_string_put(INWIWIN + 10, 730, 0x00FF00, "^");
	mlx_string_put(INWIWIN + 10, 740, 0x00FF00, "|");
	mlx_string_put(INWIWIN + 10, 760, 0x00FF00, "|");
	mlx_string_put(INWIWIN + 10, 770, 0x00FF00, "v");
	mlx_string_put(INWIWIN + 20, 745, 0x00FF00, "<-");
	mlx_string_put(INWIWIN + 20, 755, 0x00FF00, "->");
	mlx_string_put(INWIWIN + 45, 750, 0xFFFFFF, "to move");
	mlx_string_put(INWIWIN + 10, 790, 0x00FF00, "*");
	mlx_string_put(INWIWIN + 10, 804, 0x00FF00, "/");
	draw_help_text2(iw);
}
