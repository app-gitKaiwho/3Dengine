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

void put_pixel(t_point2d p, t_data d)
{
	mlx_pixel_put(d.s.mlx, d.s.win, p.x + (d.s.l / 2), p.y + (d.s.h / 2), 0xFFFFFFFF);
}

void	put_line(t_line l, t_data d)
{
	double	slope;
	int		signe;
	int		x;
	int		y;
	int		drawn_point;

	drawn_point = 0;
	signe = 1;
	x = l.a.x;
	y = l.a.y;
	slope = (double)(l.z.y - l.a.y) / (double)(l.z.x - l.a.x);
	if (fabs(slope) > 1)
	{
		if (l.a.x > l.z.x)
			signe = -1;
		while (ft_abs(x - l.z.x) > 1)
		{
			put_pixel((t_point2d){x, y}, d);
			x += signe;
			y = (slope * (x - l.a.x)) + l.a.y;
			drawn_point++;
		}
	}
	else
	{
		if (l.a.y > l.z.y)
			signe = -1;
		while (ft_abs(y - l.z.y) > 1)
		{
			put_pixel((t_point2d){x, y}, d);
			y += signe;
			x = (y - l.a.y) / slope + l.a.x;
			drawn_point++;
		}
	}
	ft_printf("%d\n", drawn_point);
}

void draw_triangle(t_triangle tri, t_data *d)
{
	t_triangle casted;

	casted.a = raycast(tri.a, *d);
	casted.b = raycast(tri.b, *d);
	casted.c = raycast(tri.c, *d);
	put_line((t_line){casted.a, casted.b}, *d);
	put_line((t_line){casted.b, casted.c}, *d);
	put_line((t_line){casted.c, casted.a}, *d);
}
