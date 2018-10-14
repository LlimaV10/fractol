/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toimage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:24:40 by dbolilyi          #+#    #+#             */
/*   Updated: 2018/08/02 15:24:41 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	pixel_put_img(t_mlx *iw, int x, int y, int color)
{
	int		*tmp;

	if ((x + iw->winx * y > 0) && (x + iw->winx * y < iw->winx * iw->winy))
	{
		tmp = (int *)iw->img_data;
		tmp += x + iw->winx * y + iw->pixel_plus;
		*tmp = color;
	}
}

void	print_brez(t_brez *b, int d, int d1, int d2)
{
	int i;

	if (b->k <= 0)
		b->dx = b->dy;
	i = 0;
	while (++i <= b->dx)
	{
		if (d > 0)
		{
			d += d2;
			b->y += b->sy;
		}
		else
			d += d1;
		if (b->k > 0)
			pixel_put_img(b->iw, b->x, b->y, b->color);
		else
			pixel_put_img(b->iw, b->y, b->x, b->color);
		b->x += b->sx;
	}
}

void	brez_line(t_mlx *iw, t_draw_line line, int color)
{
	t_brez	b;

	pixel_put_img(iw, line.x0, line.y0, color);
	b.iw = iw;
	b.color = color;
	b.sx = (line.x1 >= line.x0) ? (1) : (-1);
	b.sy = (line.y1 >= line.y0) ? (1) : (-1);
	b.dx = (line.x1 > line.x0) ? (line.x1 - line.x0) : (line.x0 - line.x1);
	b.dy = (line.y1 > line.y0) ? (line.y1 - line.y0) : (line.y0 - line.y1);
	if (abs(line.y1 - line.y0) < abs(line.x1 - line.x0))
	{
		b.x = line.x0 + b.sx;
		b.y = line.y0;
		b.k = 1;
		print_brez(&b, (b.dy * 2) - b.dx, b.dy * 2, (b.dy - b.dx) * 2);
	}
	else
	{
		b.x = line.y0 + b.sy;
		b.y = line.x0;
		b.sy = (line.x1 >= line.x0) ? (1) : (-1);
		b.sx = (line.y1 >= line.y0) ? (1) : (-1);
		b.k = 0;
		print_brez(&b, (b.dx * 2) - b.dy, b.dx * 2, (b.dx - b.dy) * 2);
	}
}

void	drawtriangle(t_mlx *iw, int points[3][2])
{
	t_draw_line line;

	line.x0 = points[0][0];
	line.y0 = points[0][1];
	line.x1 = points[1][0];
	line.y1 = points[1][1];
	brez_line(iw, line, 0x5FFF00);
	line.x1 = points[2][0];
	line.y1 = points[2][1];
	brez_line(iw, line, 0x5FFF00);
	line.x0 = points[1][0];
	line.y0 = points[1][1];
	brez_line(iw, line, 0x5FFF00);
}
