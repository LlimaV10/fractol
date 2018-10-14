/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:24:32 by dbolilyi          #+#    #+#             */
/*   Updated: 2018/08/02 15:24:33 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		key_hook2(int keycode, t_mlx *iw)
{
	if (keycode == 125 || keycode == 65364)
		update2(iw, &(iw->v.y), 300.0 / iw->v.scale / iw->winy);
	else if (keycode == 49 || keycode == 32)
		update(iw, &(iw->v.pause), (iw->v.pause == 0) ? 1 : -1);
	else if (keycode == 67 || keycode == 65450)
	{
		if (iw->v.chng_color <= 20)
			iw->v.chng_color = 0xFFFFFF;
		update(iw, &(iw->v.chng_color), -iw->v.chng_color / 20 - 100);
	}
	else if (keycode == 75 || keycode == 65455)
	{
		if (iw->v.standart_color <= 20)
			iw->v.standart_color = 0xFFFFFF;
		update(iw, &(iw->v.standart_color), -iw->v.standart_color / 20 - 100);
	}
	return (0);
}

int		key_hook(int keycode, t_mlx *iw)
{
	if (keycode == 53 || keycode == 65307)
	{
		exit(0);
	}
	else if (keycode == 69 || keycode == 65451)
	{
		if (iw->v.frac_numb != 2)
			update(iw, &(iw->v.max_iter), (iw->v.max_iter < 500) ? 10 : 0);
		else
			update(iw, &(iw->v.max_iter), (iw->v.max_iter < 100) ? 10 : 0);
	}
	else if (keycode == 78 || keycode == 65453)
		update(iw, &(iw->v.max_iter), (iw->v.max_iter >= 10) ? -10 : 0);
	else if (keycode == 124 || keycode == 65363)
		update2(iw, &(iw->v.x), 300.0 / iw->v.scale / iw->winx);
	else if (keycode == 123 || keycode == 65361)
		update2(iw, &(iw->v.x), -300.0 / iw->v.scale / iw->winx);
	else if (keycode == 126 || keycode == 65362)
		update2(iw, &(iw->v.y), -300.0 / iw->v.scale / iw->winy);
	else
		return (key_hook2(keycode, iw));
	return (0);
}

int		mouse_move(int x, int y, t_mlx *iw)
{
	if ((iw->v.pause == 0) && (iw->v.frac_numb == 0) && (x > 0) &&
			(x < WINDOW_X) && (y > 0) && (y < WINDOW_Y))
	{
		iw->v.cre = (float)y * 0.9 / (float)iw->winy - 1.5;
		iw->v.cim = (float)x * 0.5 / (float)iw->winx;
		update(iw, 0, 1);
	}
	else if ((iw->v.pause == 0) && (iw->v.frac_numb == 2) && (x > 0) &&
			(x < WINDOW_X) && (y > 0) && (y < WINDOW_Y))
	{
		iw->s.rot_change = (iw->winx - x) * 100 / (iw->winx + 1000);
		iw->s.angle = 4 + (iw->winy - y) * 126 / iw->winy;
		iw->s.rot = -iw->s.angle / 2;
		update(iw, 0, 1);
	}
	return (0);
}

void	mouse_hook2(int button, t_mlx *iw)
{
	if (button == 4)
	{
		if (iw->v.scale == 2)
		{
			iw->v.x = 0;
			iw->v.y = 0;
		}
		if (iw->v.scale > 1)
			update3(iw, &(iw->v.scale), -(iw->v.scale / 2));
	}
}

int		mouse_hook(int button, int x, int y, t_mlx *iw)
{
	if (x > 0 && x < WINDOW_X && y > 0 && y < WINDOW_Y)
	{
		if ((button == 5) && (iw->v.scale < 0x8000000000000000))
			update3(iw, &(iw->v.scale), iw->v.scale);
		else if (button == 1)
		{
			iw->v.x += (float)(x - iw->winx / 2) / (float)iw->v.scale /
					(float)iw->winx * 3;
			iw->v.y += (float)(y - iw->winy / 2) / (float)iw->v.scale /
					(float)iw->winy * 2;
			update(iw, 0, 1);
		}
		else
			mouse_hook2(button, iw);
	}
	else if (button == 1 && x > WINDOW_X && x < WINDOW_X + 200)
		switch_frac(x, y, iw);
	return (0);
}
