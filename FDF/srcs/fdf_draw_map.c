/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:02:16 by pserre-s          #+#    #+#             */
/*   Updated: 2026/01/05 14:40:58 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_draw_point(t_var *vars, int x, int y)
{
	t_point	p1;
	t_point	p2;

	p1 = vars->map.points_matrix[y][x];
	fdf_project_point(&p1, vars);
	if (x < vars->map.width - 1)
	{
		p2 = vars->map.points_matrix[y][x + 1];
		fdf_project_point(&p2, vars);
		fdf_draw_line(vars, p1, p2);
	}
	if (y < vars->map.height - 1)
	{
		p2 = vars->map.points_matrix[y + 1][x];
		fdf_project_point(&p2, vars);
		fdf_draw_line(vars, p1, p2);
	}
}

void	fdf_draw_map(t_var *vars)
{
	int		x;
	int		y;

	ft_bzero(vars->img.addr, vars->img.line_len * Y_LEN);
	y = 0;
	while (y < vars->map.height)
	{
		x = 0;
		while (x < vars->map.width)
		{
			fdf_draw_point(vars, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img.img, 0, 0);
}
