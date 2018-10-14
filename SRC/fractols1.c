/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:24:26 by dbolilyi          #+#    #+#             */
/*   Updated: 2018/08/02 15:24:27 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia(t_mlx *iw)
{
	double	zx;
	double	zy;
	double	xtmp;
	int		iter;

	zx = 1.5 * (iw->j - iw->winx / 2) / (0.5 * iw->v.scale *
			iw->winx) + iw->v.x;
	zy = (iw->i - iw->winy / 2) / (0.5 * iw->v.scale * iw->winy) + iw->v.y;
	iter = 0;
	while ((zx * zx + zy * zy < 4) && (iter < iw->v.max_iter))
	{
		xtmp = zx * zx - zy * zy + iw->v.cre;
		zy = 2 * zx * zy + iw->v.cim;
		zx = xtmp;
		iter++;
	}
	if (iter == iw->v.max_iter)
		pixel_put_img(iw, iw->j, iw->i, 0);
	else
		pixel_put_img(iw, iw->j, iw->i, iter * iw->v.standart_color +
				iw->v.chng_color);
}

void	mandelbrot(t_mlx *iw)
{
	t_mand	m;

	m.zx = 1.5 * (iw->j - iw->winx / 2) / (0.5 * iw->v.scale * iw->winx) +
		iw->v.x - 0.5;
	m.zy = (iw->i - iw->winy / 2) / (0.5 * iw->v.scale * iw->winy) + iw->v.y;
	m.x = 0.0;
	m.y = 0.0;
	m.iter = 0;
	while (m.x * m.x + m.y * m.y < 4 && m.iter < iw->v.max_iter)
	{
		m.xtemp = m.x * m.x - m.y * m.y + m.zx;
		m.y = 2 * m.x * m.y + m.zy;
		m.x = m.xtemp;
		m.iter++;
	}
	if (m.iter == iw->v.max_iter)
		pixel_put_img(iw, iw->j, iw->i, 0);
	else
		pixel_put_img(iw, iw->j, iw->i, m.iter * iw->v.standart_color +
				iw->v.chng_color);
}

void	get_tr_coord(int points[3][2], int radius, int angle, int rot)
{
	int a;

	a = 2 * radius * cos(angle / 2 * 0.0174533);
	points[1][0] = points[0][0] + sin(rot * 0.0174533) * a;
	points[1][1] = points[0][1] + cos(rot * 0.0174533) * a;
	points[2][0] = points[0][0] + sin((180 - rot - angle) * 0.0174533) * a;
	points[2][1] = points[0][1] - cos((180 - rot - angle) * 0.0174533) * a;
}

void	sierpinski(t_sier *s, int radius, int angle, int iter)
{
	t_sier	buf;

	get_tr_coord(s->points, radius, angle, s->rot);
	drawtriangle(s->iw, s->points);
	if (iter < 1)
		return ;
	buf.iw = s->iw;
	buf.rot_change = s->rot_change;
	buf.points[0][0] = s->points[0][0];
	buf.points[0][1] = s->points[0][1];
	buf.rot = s->rot;
	sierpinski(&buf, radius / 2 + 1, angle, iter - 1);
	buf.points[0][0] = (s->points[0][0] + s->points[1][0]) / 2;
	buf.points[0][1] = (s->points[0][1] + s->points[1][1]) / 2;
	buf.rot = s->rot - s->rot_change;
	sierpinski(&buf, radius / 2 + 1, angle, iter - 1);
	buf.points[0][0] = (s->points[0][0] + s->points[2][0]) / 2;
	buf.points[0][1] = (s->points[0][1] + s->points[2][1]) / 2;
	buf.rot = s->rot + s->rot_change;
	sierpinski(&buf, radius / 2 + 1, angle, iter - 1);
}

void	sierpinski_triangle(t_mlx *iw)
{
	iw->s.points[0][0] = iw->winx / 2;
	iw->s.points[0][1] = iw->winy / 26;
	iw->s.iw = iw;
	sierpinski(&(iw->s), (int)((float)iw->winy / 2.45f), iw->s.angle,
			iw->v.max_iter / 10);
}
