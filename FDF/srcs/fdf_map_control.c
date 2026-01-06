/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:31:52 by pserre-s          #+#    #+#             */
/*   Updated: 2026/01/06 16:02:22 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_keyboard_hook(int key, t_var *vars)
{
	if (key == K_LEFT)
		vars->x_offset -= 10;
	else if (key == K_RIGHT)
		vars->x_offset += 10;
	else if (key == K_DOWN)
		vars->y_offset -= 10;
	else if (key == K_UP)
		vars->y_offset += 10;
	else if (key == K_A)
		vars->angle_z -= 0.05;
	else if (key == K_D)
		vars->angle_z += 0.05;
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
		vars->zoom += 0.5;
	else if (button == 5)
	{
		vars->zoom -= 0.5;
		if (vars->zoom < 0.5)
			vars->zoom = 0.5;
	}
	fdf_draw_map(vars);
	return (0);
}

void	fdf_rotate_z(double *x, double *y, double angle)
{
	double	prev_x;
	double	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(angle) - prev_y * sin(angle);
	*y = prev_x * sin(angle) + prev_y * cos(angle);
}
