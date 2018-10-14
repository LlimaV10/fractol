/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:24:24 by dbolilyi          #+#    #+#             */
/*   Updated: 2018/08/02 15:24:25 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_help_lines2(t_mlx *iw, t_draw_line *line)
{
	line->y0 = 550;
	line->x1 = 0;
	brez_line(iw, *line, 0xFFFF00);
	line->x0 = 40;
	line->x1 = 40;
	brez_line(iw, *line, 0xFFFF00);
	line->x0 = 80;
	line->x1 = 80;
	brez_line(iw, *line, 0xFFFF00);
	line->x0 = 120;
	line->x1 = 120;
	brez_line(iw, *line, 0xFFFF00);
	line->x0 = 160;
	line->x1 = 160;
	brez_line(iw, *line, 0xFFFF00);
	line->x0 = 199;
	line->x1 = 199;
	brez_line(iw, *line, 0xFFFF00);
	line->y0 = 0;
	line->y1 = WINDOW_Y;
	brez_line(iw, *line, 0xFFFF00);
}

void	draw_help_lines(t_mlx *iw)
{
	t_draw_line line;

	line.x0 = 0;
	line.x1 = 0;
	line.y0 = 0;
	line.y1 = WINDOW_Y;
	brez_line(iw, line, 0xFFFF00);
	line.y1 = 0;
	line.x1 = 200;
	brez_line(iw, line, 0xFFFF00);
	line.y1 = 200;
	line.y0 = 200;
	brez_line(iw, line, 0xFFFF00);
	line.y1 = 400;
	line.y0 = 400;
	brez_line(iw, line, 0xFFFF00);
	line.y1 = 550;
	line.y0 = 550;
	brez_line(iw, line, 0xFFFF00);
	line.y1 = 590;
	line.y0 = 590;
	brez_line(iw, line, 0xFFFF00);
	draw_help_lines2(iw, &line);
}

void	get_help_img(t_mlx *iw)
{
	void	*tmp;

	iw->winx = 200;
	iw->winy = 200;
	iw->img_ptr = mlx_new_image(iw->init, iw->winx, WINDOW_Y);
	iw->img_data = mlx_get_data_addr(iw->img_ptr, &(iw->v.bpp),
			&(iw->v.size_line), &(iw->v.endian));
	tmp = iw->img_data;
	iw->s.rot = -30;
	iw->s.rot_change = 0;
	iw->s.angle = 60;
	draw_help_fract(iw);
	draw_help_colors(iw);
	iw->img_data = tmp;
	iw->winy = WINDOW_Y;
	draw_help_lines(iw);
	iw->help_img_ptr = iw->img_ptr;
	iw->winx = WINDOW_X;
	iw->winy = WINDOW_Y;
}
