/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:31:52 by pserre-s          #+#    #+#             */
/*   Updated: 2026/01/12 02:02:06 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_update_translation_and_scale(t_var *vars)
{
	if (vars->keys[K_LEFT])
		vars->x_offset -= 5;
	if (vars->keys[K_RIGHT])
		vars->x_offset += 5;
	if (vars->keys[K_DOWN])
		vars->y_offset -= 5;
	if (vars->keys[K_UP])
		vars->y_offset += 5;
	if (vars->keys[K_8])
		vars->z_scale += 0.01;
	if (vars->keys[K_2])
		vars->z_scale -= 0.01;
}

static void	fdf_update_rotation(t_var *vars)
{
	if (vars->keys[K_A])
		vars->angle_z -= 0.1;
	if (vars->keys[K_D])
		vars->angle_z += 0.1;
	if (vars->keys[K_S])
		vars->angle_x -= 0.1;
	if (vars->keys[K_W])
		vars->angle_x += 0.1;
	if (vars->keys[K_E])
		vars->angle_y -= 0.1;
	if (vars->keys[K_Q])
		vars->angle_y += 0.1;
}

void	fdf_update_movement(t_var *vars)
{
	fdf_update_translation_and_scale(vars);
	fdf_update_rotation(vars);
	if (vars->keys[K_ESC])
		close_window(vars);
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
