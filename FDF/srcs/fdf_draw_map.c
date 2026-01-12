/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:02:16 by pserre-s          #+#    #+#             */
/*   Updated: 2026/01/12 01:31:09 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init_sin_cos(t_var *vars)
{
	vars->cos_x = cos(vars->angle_x);
	vars->sin_x = sin(vars->angle_x);
	vars->cos_y = cos(vars->angle_y);
	vars->sin_y = sin(vars->angle_y);
	vars->cos_z = cos(vars->angle_z);
	vars->sin_z = sin(vars->angle_z);
}

int	fdf_draw_map(t_var *vars)
{
	int		x;
	int		y;

	ft_bzero(vars->img.addr, vars->img.line_len * Y_LEN);
	fdf_project_all_points(vars);
	y = 0;
	while (y < vars->map.height)
	{
		x = 0;
		while (x < vars->map.width)
		{
			if (x < vars->map.width - 1)
				fdf_draw_line(vars, vars->map.points_matrix[y][x],
					vars->map.points_matrix[y][x + 1]);
			if (y < vars->map.height - 1)
				fdf_draw_line(vars, vars->map.points_matrix[y][x],
					vars->map.points_matrix[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img.img, 0, 0);
	return (0);
}
