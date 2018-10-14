/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:24:35 by dbolilyi          #+#    #+#             */
/*   Updated: 2018/08/02 15:24:36 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		choose_fractal2(t_mlx *iw, char **argv)
{
	if ((ft_strcmp(argv[1], "pyramid") == 0))
		iw->v.frac_numb = 5;
	else if ((ft_strcmp(argv[1], "cock") == 0))
		iw->v.frac_numb = 6;
	else if ((ft_strcmp(argv[1], "star") == 0))
		iw->v.frac_numb = 7;
	else
	{
		write(1, "Unknown fractol name!\nAvailable fractols:\n\tjulia\n\t", 50);
		write(1, "mandelbrot\n\ttriangle\n", 21);
		write(1, "\tburningship\n\tbuffalo\n\tpyramid\n\tcock\n\tstar\n", 43);
		return (0);
	}
	return (1);
}

int		choose_fractal(t_mlx *iw, int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "usage: fractol fractol_name\nAvailable fractols:\n\tjulia",
			54);
		write(1, "\n\tmandelbrot\n\ttriangle\n", 23);
		write(1, "\tburningship\n\tbuffalo\n\tpyramid\n\tcock\n\tstar\n", 43);
		return (0);
	}
	if (ft_strcmp(argv[1], "julia") == 0)
		iw->v.frac_numb = 0;
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		iw->v.frac_numb = 1;
	else if ((ft_strcmp(argv[1], "triangle") == 0))
		iw->v.frac_numb = 2;
	else if ((ft_strcmp(argv[1], "burningship") == 0))
		iw->v.frac_numb = 3;
	else if ((ft_strcmp(argv[1], "buffalo") == 0))
		iw->v.frac_numb = 4;
	else
		return (choose_fractal2(iw, argv));
	return (1);
}

void	set_defaultview(t_mlx *iw)
{
	iw->pixel_plus = 0;
	iw->v.max_iter = 50;
	iw->v.y = 0;
	iw->v.cre = -0.705;
	iw->v.cim = 0.3;
	iw->v.scale = 1;
	iw->v.pause = 0;
	iw->v.chng_color = 4419667;
	iw->v.standart_color = 67383;
}

int		main(int argc, char **argv)
{
	t_mlx	iw;

	iw.v.x = 0;
	if (choose_fractal(&iw, argc, argv) == 0)
		return (0);
	set_defaultview(&iw);
	iw.init = mlx_init();
	iw.win = mlx_new_window(iw.init, WINDOW_X + 200, WINDOW_Y, "fractol");
	get_help_img(&iw);
	iw.img_ptr = mlx_new_image(iw.init, WINDOW_X, WINDOW_Y);
	iw.img_data = mlx_get_data_addr(iw.img_ptr, &(iw.v.bpp),
			&(iw.v.size_line), &(iw.v.endian));
	threads_fract(&iw);
	mlx_put_image_to_window(iw.init, iw.win, iw.help_img_ptr, WINDOW_X, 0);
	draw_help_text(&iw);
	mlx_hook(iw.win, 2, (1L << 0), key_hook, &iw);
	mlx_hook(iw.win, 6, 0, mouse_move, &iw);
	mlx_mouse_hook(iw.win, mouse_hook, &iw);
	mlx_loop(iw.init);
}
