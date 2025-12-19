/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:31:52 by pserre-s          #+#    #+#             */
/*   Updated: 2025/12/19 20:50:42 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_keyboard_hook(int key, t_var *vars)
{
	if (key == K_LEFT)
		vars->x_offset -= 10;
	else if (key == K_RIGHT)
		vars->x_offset += 10;
	else if (key == K_UP)
		vars->y_offset -= 10;
	else if (key == K_DOWN)
		vars->y_offset += 10;
	else if (key == K_ESC)
		close_window(vars);
	fdf_draw_map(vars);
	return (0);
}

int	fdf_mouse_hook(int button, int x, int y, t_var *vars)
{
	(void)x;
	(void)y;

	if (button == 4)
		vars->zoom += 1;
	else if (button == 5)
	{
		vars->zoom -= 1;
		if (vars->zoom < 1)
			vars->zoom = 1;
	}
	fdf_draw_map(vars);
	return (0);
}
