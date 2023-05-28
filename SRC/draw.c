/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:07:21 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/28 15:07:21 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "3D.h"

void put_pixel(t_point p, t_data *d)
{
	mlx_pixel_put(d->s.mlx, d->s.win, p.x + (d->s.l / 2), p.y + (d->s.h / 2), 0xFFFFFFFF);
}

void draw_triangle(t_triangle tri, t_data *d)
{
	t_triangle casted;

	ft_printf("A[%f %f %f]\n", tri.a.x, tri.a.y, tri.a.z);
	ft_printf("B[%f %f %f]\n", tri.b.x, tri.b.y, tri.b.z);
	ft_printf("C[%f %f %f]\n", tri.c.x, tri.c.y, tri.c.z);
	casted.a = raycast(tri.a, *d);
	casted.b = raycast(tri.b, *d);
	casted.c = raycast(tri.c, *d);
	put_pixel(tri.a, d);
	put_pixel(tri.b, d);
	put_pixel(tri.c, d);
	ft_printf("A[%f %f %f]\n", casted.a.x, casted.a.y, casted.a.z);
	ft_printf("B[%f %f %f]\n", casted.b.x, casted.b.y, casted.b.z);
	ft_printf("C[%f %f %f]\n", casted.c.x, casted.c.y, casted.c.z);
}

