/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:07:05 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/28 16:07:05 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "3D.h"

int	mouse_press(int button, int x, int y, void *param)
{
	struct data	*d;

	(void)x;
	(void)y;
	d = (t_data *)param;
	if (button == L_CLICK)
		d->m.is_pressed ^= 1;
	return (0);
}
