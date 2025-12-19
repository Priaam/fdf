/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:51:47 by pserre-s          #+#    #+#             */
/*   Updated: 2025/12/19 18:02:18 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_init_brensenham(t_bresenham *b, t_point start, t_point end)
{

	b->dx = abs((int)end.x_proj - (int)start.x_proj);
	b->dy = abs((int)end.y_proj - (int)start.y_proj);
	if (start.x_proj < end.x_proj)
		b->sx = 1;
	else
		b->sx = -1;
	if (start.y_proj < end.y_proj)
		b->sy = 1;
	else
		b->sy = -1;
	b->error = b->dx - b->dy;
}

void	fdf_draw_line(t_var *vars, t_point start, t_point end)
{
	t_bresenham	b;

	fdf_init_brensenham(&b, start, end);
	while ((int)start.x_proj != (int)end.x_proj
		|| (int)start.y_proj != (int)end.y_proj)
	{
		my_pixel_put(&vars->img, (int)start.x_proj,
			(int)start.y_proj, start.color);
		b.temp_error = 2 * b.error;
		if (b.temp_error > -b.dy)
		{
			b.error -= b.dy;
			start.x_proj += b.sx;
		}
		if (b.temp_error < b.dx)
		{
			b.error += b.dx;
			start.y_proj += b.sy;
		}
	}
	my_pixel_put(&vars->img, (int)end.x_proj, (int)end.y_proj, end.color);
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
