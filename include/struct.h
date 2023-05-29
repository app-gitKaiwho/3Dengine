/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:54:56 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:52:04 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct img
{
	void	*img;
	char	*data;
	int		bpp;
	int		line_size;
	int		endian;
}t_img;

typedef struct window
{
	void	*win;
	void	*mlx;
	int		l;
	int		h;
}t_window;

typedef struct point
{
	int	x;
	int	y;
	int	z;
}t_point;

typedef struct map
{
	t_point	**points;
	int		j;
	int		i;
}t_map;

typedef struct rgb
{
	int	red;
	int	green;
	int	blue;
}t_RGB;

//a début, z fin
typedef struct line
{
	t_point	a;
	t_point	z;
}t_line;

typedef struct tri
{
    t_point a;
    t_point b;
    t_point c;
}t_triangle;

typedef struct mouse
{
	int	x;
	int	y;
	int is_pressed;
}t_mouse;


typedef struct data
{
	t_img		i;
	t_window	s;
	t_RGB		c;
	t_point		a;
	t_point		o;
	int			f;
	t_mouse		m;
	float		g_size;
}t_data;

typedef struct point2d
{
	int	x;
	int	y;
}t_point2d;

typedef struct iterator
{
	int	j;
	int	i;
	int	k;
}t_iterator;

#endif /*!STRUCT_H */