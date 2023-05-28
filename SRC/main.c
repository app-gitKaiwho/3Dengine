/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:52:34 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/28 13:52:34 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "3D.h"

void	error_handler(char *txt, int code)
{
	ft_printf("%s\n", txt);
	exit(code);
}

int	loopydyloop(void *param)
{
	struct data	*d;

	d = (t_data *)param;
	mlx_mouse_get_pos(d->s.mlx, d->s.win, &(d->m.x), &(d->m.y));
	d->m = (t_mouse){d->m.x - (d->s.l / 2), d->m.y - (d->s.h / 2),
		d->m.is_pressed};
	write(1, "bruh\n", d->f * 0);
	return (0);
}

void	ini_data(t_data *d)
{
	d->s = (t_window){.l = SCREEN_LENGTH,
		.h = SCREEN_HEIGHT, .mlx = mlx_init()};
	if (!d->s.mlx)
		error_handler("window could not be initialized !", 2);
	d->s.win = mlx_new_window(d->s.mlx, d->s.l, d->s.h, "Fdf");
	d->i.img = mlx_new_image(d->s.mlx, d->s.l, d->s.h);
	d->i.data = mlx_get_data_addr(d->i.img, &d->i.bpp,
			&d->i.line_size, &d->i.endian);
	d->c = (t_RGB){255, 255, 255};
	d->a = (t_point){0.0, 00.0, 0.0};
	d->o = (t_point){0.0, 0.0, 0.0};
	d->m = (t_mouse){0, 0, 0};
	d->f = 10000;
}

void	setup_controls(t_data *d)
{
	mlx_mouse_hook(d->s.win, mouse_press, d);
	mlx_hook(d->s.win, KeyPress, 0, keyhook, d);
	mlx_hook(d->s.win, DestroyNotify, DestroyNotify, exit_hook, NULL);
}

int	main(int ac, char **av)
{
	t_data	d;
	t_triangle tri;

	(void)av;
	if (ac != 2)
		error_handler("invalid arg. number", 1);
	tri = (t_triangle){{0.0, 0.0, 0},
					   {100.0, 100.0, 0},
					   {500.0, -100.0, 0}};
	ini_data(&d);
	setup_controls(&d);
	draw_triangle(tri, &d);
	mlx_loop_hook(d.s.mlx, loopydyloop, &d);
	mlx_loop(d.s.mlx);
	free(d.s.mlx);
}
