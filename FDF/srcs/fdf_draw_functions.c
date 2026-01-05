/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:51:47 by pserre-s          #+#    #+#             */
/*   Updated: 2026/01/05 14:40:35 by pserre-s         ###   ########.fr       */
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

static void	fdf_iso(double *x, double *y, int z)
{
	double	previous_x;
	double	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	fdf_project_point(t_point *points, t_var *vars)
{
	points->x_proj = (double)points->x * vars->zoom;
	points->y_proj = (double)points->y * vars->zoom;
	fdf_iso(&points->x_proj, &points->y_proj, points->z * vars->zoom);
	points->x_proj += vars->x_offset;
	points->y_proj += vars->y_offset;
}
