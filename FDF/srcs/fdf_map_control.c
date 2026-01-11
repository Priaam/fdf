/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:31:52 by pserre-s          #+#    #+#             */
/*   Updated: 2026/01/11 22:05:28 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_update_movement(t_var *vars)
{
	if (vars->keys[K_LEFT])
		vars->x_offset -= 5;
	if (vars->keys[K_RIGHT])
		vars->x_offset += 5;
	if (vars->keys[K_DOWN])
		vars->y_offset -= 5;
	if (vars->keys[K_UP])
		vars->y_offset += 5;
	if (vars->keys[K_A])
		vars->angle_z -= 0.1;
	if (vars->keys[K_D])
		vars->angle_z += 0.1;
	// else if (vars->keys[K_S)
	// 	vars->angle_x -= 0.2;
	// else if (vars->keys[K_W)
	// 	vars->angle_x += 0.2;
	if (vars->keys[K_E])
		vars->angle_y -= 0.1;
	if (vars->keys[K_Q])
		vars->angle_y += 0.1;
	if (vars->keys[K_ESC])
		close_window(vars);
	return (0);
}

int	fdf_mouse_hook(int button, int x, int y, t_var *vars)
{
	double	zoom_factor;
	double	prev_zoom;

	prev_zoom = vars->zoom;
	if (button == 4)
		vars->zoom *= 1.1;
	else if (button == 5)
	{
		vars->zoom /= 1.1;
		if (vars->zoom < 0.1)
			vars->zoom = 0.1;
	}
	zoom_factor = vars->zoom / prev_zoom;
	vars->x_offset = x - (x - vars->x_offset) * zoom_factor;
	vars->y_offset = y - (y - vars->y_offset) * zoom_factor;
	return (0);
}

int	fdf_key_press(int key, t_var *vars)
{
	if (key < 65536)
		vars->keys[key] = 1;
	return (0);
}

int	fdf_key_release(int key, t_var *vars)
{
	if (key < 65536)
		vars->keys[key] = 0;
	return (0);
}

// void	fdf_reset_position(t_var *vars)
// {
// 	vars->angle_x = 0.0;
// 	vars->angle_y = 0.0;
// 	vars->angle_z = 0.0;
// }
