/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:24:28 by dbolilyi          #+#    #+#             */
/*   Updated: 2018/08/02 15:24:29 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	buffalo(t_mlx *iw)
{
	t_mand	m;

	m.zx = 1.5 * (iw->j - iw->winx / 2) / (0.5 * iw->v.scale * iw->winx) +
		iw->v.x - 1;
	m.zy = (iw->i - iw->winy / 2) / (0.5 * iw->v.scale * iw->winy) +
		iw->v.y + 0.5;
	m.x = 0.0;
	m.y = 0.0;
	m.iter = 0;
	while (m.x * m.x + m.y * m.y < 4 && m.iter < iw->v.max_iter)
	{
		m.xtemp = fabs(m.x * m.x - m.y * m.y) + m.zx;
		m.y = -2 * fabs(m.x * m.y) + m.zy;
		m.x = m.xtemp;
		m.iter++;
	}
	if (m.iter == iw->v.max_iter)
		pixel_put_img(iw, iw->j, iw->i, 0);
	else
		pixel_put_img(iw, iw->j, iw->i, m.iter * iw->v.standart_color +
				iw->v.chng_color);
}

void	cock(t_mlx *iw)
{
	t_mand	m;

	m.zx = 1.5 * (iw->j - iw->winx / 2) / (0.5 * iw->v.scale * iw->winx) +
		iw->v.x - 0.5;
	m.zy = (iw->i - iw->winy / 2) / (0.5 * iw->v.scale * iw->winy) + iw->v.y;
	m.x = 0;
	m.y = 0;
	m.iter = 0;
	while (m.x * m.x + m.y * m.y < 4 && m.iter < iw->v.max_iter)
	{
		m.xtemp = m.x * m.x - m.y * m.y + m.zx;
		m.y = -2 * m.x * fabs(m.y) + m.zy;
		m.x = m.xtemp;
		m.iter++;
	}
	if (m.iter == iw->v.max_iter)
		pixel_put_img(iw, iw->j, iw->i, 0);
	else
		pixel_put_img(iw, iw->j, iw->i, m.iter * iw->v.standart_color +
				iw->v.chng_color);
}

void	burningship(t_mlx *iw)
{
	t_mand	m;

	m.zx = 1.5 * (iw->j - iw->winx / 2) / (0.5 * iw->v.scale * iw->winx) +
		iw->v.x - 0.5;
	m.zy = (iw->i - iw->winy / 2) / (0.5 * iw->v.scale * iw->winy) +
		iw->v.y - 0.5;
	m.x = 0;
	m.y = 0;
	m.iter = 0;
	while (m.x * m.x + m.y * m.y < 4 && m.iter < iw->v.max_iter)
	{
		m.xtemp = m.x * m.x - m.y * m.y + m.zx;
		m.y = fabs(2 * m.x * m.y) + m.zy;
		m.x = fabs(m.xtemp);
		m.iter++;
	}
	if (m.iter == iw->v.max_iter)
		pixel_put_img(iw, iw->j, iw->i, 0);
	else
		pixel_put_img(iw, iw->j, iw->i, m.iter * iw->v.standart_color +
				iw->v.chng_color);
}

void	pyramid(t_mlx *iw)
{
	t_mand	m;

	m.zx = 1.5 * (iw->j - iw->winx / 2) / (0.5 * iw->v.scale * iw->winx) +
		iw->v.x - 2;
	m.zy = (iw->i - iw->winy / 2) / (0.5 * iw->v.scale * iw->winy) + iw->v.y;
	m.x = 0.0;
	m.y = 0.0;
	m.iter = 0;
	while (m.x * m.x + m.y * m.y < 4 && m.iter < iw->v.max_iter)
	{
		m.xtemp = m.x * m.x + 0.15 * m.y * m.y + m.zx;
		m.y = 2 * m.x * m.y + m.zy;
		m.x = m.xtemp;
		m.iter++;
	}
	if (m.iter == iw->v.max_iter)
		pixel_put_img(iw, iw->j, iw->i, 0xFFFFFF);
	else
		pixel_put_img(iw, iw->j, iw->i, m.iter * iw->v.standart_color +
				iw->v.chng_color);
}

void	bigstar(t_mlx *iw)
{
	t_mand	m;

	m.zx = 1.5 * (iw->j - iw->winx / 2) / (0.5 * iw->v.scale * iw->winx) +
		iw->v.x - 0.3;
	m.zy = (iw->i - iw->winy / 2) / (0.5 * iw->v.scale * iw->winy) + iw->v.y;
	m.x = 0.0;
	m.y = 0.0;
	m.iter = 0;
	while (m.x * m.x + m.y * m.y < 4 && m.iter < iw->v.max_iter)
	{
		m.xtemp = m.x * m.x - m.y * m.y + m.zx;
		m.y = -2 * m.x * m.y + m.zy;
		m.x = m.xtemp;
		m.iter++;
	}
	if (m.iter == iw->v.max_iter)
		pixel_put_img(iw, iw->j, iw->i, 0);
	else
		pixel_put_img(iw, iw->j, iw->i, m.iter * iw->v.standart_color +
				iw->v.chng_color);
}
