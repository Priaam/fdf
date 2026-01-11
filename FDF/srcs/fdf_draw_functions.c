/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:51:47 by pserre-s          #+#    #+#             */
/*   Updated: 2026/01/11 22:26:26 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_init_brensenham(t_bresenham *b, t_point *start, t_point *end)
{
	start->x = (int)start->x_proj;
	start->y = (int)start->y_proj;
	end->x = (int)end->x_proj;
	end->y = (int)end->y_proj;
	b->dx = abs(end->x - start->x);
	b->dy = abs(end->y - start->y);
	if (start->x_proj < end->x_proj)
		b->sx = 1;
	else
		b->sx = -1;
	if (start->y_proj < end->y_proj)
		b->sy = 1;
	else
		b->sy = -1;
	b->error = b->dx - b->dy;
}

void	fdf_draw_line(t_var *vars, t_point p1, t_point p2)
{
	t_bresenham	b;

	fdf_init_brensenham(&b, &p1, &p2);
	while (p1.x != p2.x || p1.y != p2.y)
	{
		my_pixel_put(&vars->img, p1.x, p1.y, p1.color);
		b.temp_error = 2 * b.error;
		if (b.temp_error > -b.dy)
		{
			b.error -= b.dy;
			p1.x += b.sx;
		}
		if (b.temp_error < b.dx)
		{
			b.error += b.dx;
			p1.y += b.sy;
		}
	}
	my_pixel_put(&vars->img, p2.x, p2.y, p1.color);
}

void	fdf_project_point(t_point *points, t_var *vars)
{
	double	x;
	double	y;
	double	z;
	double	prev_x;
	double	prev_y;

	// 1. Mise à l'échelle et centrage
	x = (points->x - vars->map.width / 2.0) * vars->zoom;
	y = (points->y - vars->map.height / 2.0) * vars->zoom;
	z = (points->z * vars->zoom) * vars->z_scale;

	// 2. Application des rotations (Celles-ci permettent de bouger avec W,S,A,D...)
	prev_y = y;
	y = prev_y * vars->cos_x - z * vars->sin_x;
	z = prev_y * vars->sin_x + z * vars->cos_x;
	prev_x = x;
	x = prev_x * vars->cos_y + z * vars->sin_y;
	z = -prev_x * vars->sin_y + z * vars->cos_y;
	prev_x = x;
	prev_y = y;
	x = prev_x * vars->cos_z - prev_y * vars->sin_z;
	y = prev_x * vars->sin_z + prev_y * vars->cos_z;

	// 3. Projection ISOMÉTRIQUE (Pour donner l'effet 3D de base)
	points->x_proj = (x - y) * cos(0.523599); // 0.523599 rad = 30 degrés
	points->y_proj = (x + y) * sin(0.523599) - z;

	// 4. Positionnement final à l'écran
	points->x_proj += vars->x_offset;
	points->y_proj += vars->y_offset;
}

// int	fdf_get_color(int start_color, int end_color, double pourcentage)
// {
// 	int	r;
// 	int	g;
// 	int	b;

// 	if (start_color == end_color)
// 		return (start_color);
// 	r = (start_color)
// }
