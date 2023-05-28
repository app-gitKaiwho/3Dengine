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

double area(t_triangle tri)
{
    return ((ft_abs(tri.a.x * (tri.b.y-tri.c.y) + tri.b.x * 
		(tri.c.y-tri.a.y) + tri.c.x * (tri.a.y-tri.b.y))) * 0.5)
}

bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
	double A;
	double A1;
	double A2;
	double A3;

	A = area(x1, y1, x2, y2, x3, y3);
	A1 = area(x, y, x2, y2, x3, y3);
	A2 = area(x1, y1, x, y, x3, y3);
	A3 = area(x1, y1, x2, y2, x, y);
   return (A == A1 + A2 + A3);
}

void draw_triangle(t_triangle tri, t_data *d)
{
	t_triangle casted;
	int	j;
	int i;

	casted.a = raycast(tri.a, *d);
	casted.b = raycast(tri.b, *d);
	casted.c = raycast(tri.c, *d);

}
