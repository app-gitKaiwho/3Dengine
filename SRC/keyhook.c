/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:46:36 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:42:44 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "3D.h"

int	exit_hook(void)
{
	exit(EXIT_SUCCESS);
}

void	keyhook2(int keycode, t_data *d)
{
	if (keycode == BARREL_ROLL_LEFT)
		d->a.z -= 5;
	if (keycode == BARREL_ROLL_RIGHT)
		d->a.z += 5;
	if (keycode == PLUS)
		d->o.z += 50;
	if (keycode == MINUS && d->o.z >= -d->f * 0.7)
		d->o.z -= 50;
	if (keycode == ISO_VIEW)
		d->a = (t_point){45.0, 30.0, -20.0};
	if (keycode == FRONT_VIEW)
		d->a = (t_point){0.0, 0.0, 0.0};
	if (keycode == RESET)
	{
		d->a = (t_point){0.0, 0.0, 0.0};
		d->o = (t_point){0.0, 0.0, 0.0};
	}
}

int	keyhook(int keycode, void *param)
{
	struct data	*d;

	d = (t_data *)param;
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (keycode == ROT_UP)
		d->a.x += 5;
	if (keycode == ROT_DOWN)
		d->a.x -= 5;
	if (keycode == ROT_LEFT)
		d->a.y -= 5;
	if (keycode == ROT_RIGHT)
		d->a.y += 5;
	if (keycode == ARROW_UP)
		d->o.y -= 50;
	if (keycode == ARROW_DOWN)
		d->o.y += 50;
	if (keycode == ARROW_LEFT)
		d->o.x -= 50;
	if (keycode == ARROW_RIGHT)
		d->o.x += 50;
	keyhook2(keycode, d);
	return (0);
}
