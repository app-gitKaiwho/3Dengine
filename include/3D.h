/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:54:56 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:52:02 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREED_H
# define TREED_H

# define SCREEN_LENGTH 1980
# define SCREEN_HEIGHT 1080
# define SIZE 100

# include "mlx.h"
# include "stdlib.h"
# include "unistd.h"
# include "hook.h"
# include "math.h"
# include "ft_libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "struct.h"
# include <X11/Xlib.h>
void	error_handler(char *txt, int code);

//cast

t_point	raycast(t_point point, t_data d);

//draw

void draw_triangle(t_triangle tri, t_data *d);

//Hook
int     exit_hook(void);
void    keyhook2(int keycode, t_data *d);
int     keyhook(int keycode, void *param);
int     mouse_press(int button, int x, int y, void *param);
#endif /*!TREED_H */