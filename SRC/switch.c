/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:24:37 by dbolilyi          #+#    #+#             */
/*   Updated: 2018/08/02 15:24:38 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	reset_view(t_mlx *iw)
{
	iw->v.x = 0;
	iw->v.max_iter = 50;
	iw->v.y = 0;
	iw->v.cre = -0.705;
	iw->v.cim = 0.3;
	iw->v.scale = 1;
	iw->v.pause = 0;
	iw->s.rot = -30;
	iw->s.rot_change = 0;
	iw->s.angle = 60;
}

void	switch_color(int x, int y, t_mlx *iw)
{
	x -= WINDOW_X;
	if (y > WINDOW_Y - 50 && y < WINDOW_Y && x > 0)
	{
		if (x < 50)
		{
			iw->v.chng_color = 0;
			iw->v.standart_color = 0xFFF000;
		}
		else if (x < 100)
		{
			iw->v.chng_color = 4419667;
			iw->v.standart_color = 67383;
		}
		else if (x < 150)
		{
			iw->v.chng_color = 44034;
			iw->v.standart_color = 15141243;
		}
		else if (x < 200)
		{
			iw->v.chng_color = 1666539;
			iw->v.standart_color = 8410;
		}
		update(iw, 0, 1);
	}
}

void	switch_frac2(t_mlx *iw, int numb)
{
	iw->v.frac_numb = numb;
	reset_view(iw);
	update(iw, 0, 1);
}

void	switch_frac(int x, int y, t_mlx *iw)
{
	if (y > 0 && y < 200 && iw->v.frac_numb != 0)
		switch_frac2(iw, 0);
	else if (y > 200 && y < 400 && iw->v.frac_numb != 1)
		switch_frac2(iw, 1);
	else if (y > 400 && y < 550 && iw->v.frac_numb != 2)
		switch_frac2(iw, 2);
	else if (y > 550 && y < 595)
	{
		if (x > WINDOW_X && x < WINDOW_X + 40 && iw->v.frac_numb != 3)
			switch_frac2(iw, 3);
		else if (x > WINDOW_X + 40 && x < WINDOW_X + 80 && iw->v.frac_numb != 4)
			switch_frac2(iw, 4);
		else if (x > WINDOW_X + 80 && x < WINDOW_X + 120 &&
				iw->v.frac_numb != 5)
			switch_frac2(iw, 5);
		else if (x > WINDOW_X + 120 && x < WINDOW_X + 160 &&
				iw->v.frac_numb != 6)
			switch_frac2(iw, 6);
		else if (x > WINDOW_X + 160 && x < WINDOW_X + 200 &&
				iw->v.frac_numb != 7)
			switch_frac2(iw, 7);
	}
	else
		switch_color(x, y, iw);
}
