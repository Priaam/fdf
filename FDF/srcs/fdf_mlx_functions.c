/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:51:19 by pserre-s          #+#    #+#             */
/*   Updated: 2026/01/06 16:07:10 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char	*offset;

	if (x < 0 || x >= X_LEN || y < 0 || y >= Y_LEN)
		return ;
	offset = data->addr + (y * data->line_len)
		+ (x * (data->bits_per_pixel / 8));
	*(unsigned int *)offset = color;
}

void	setup_hooks(t_var *vars)
{
	mlx_key_hook(vars->window, fdf_keyboard_hook, vars);
	mlx_mouse_hook(vars->window, fdf_mouse_hook, vars);
	mlx_hook(vars->window, 17, 1L << 0, close_window, vars);
}

#ifdef __linux__

static void	clean_mlx(void *mlx_ptr)
{
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
#else

static void	clean_mlx(void *mlx_ptr)
{
	free(mlx_ptr);
}
#endif

int	close_window(t_var *vars)
{
	if (vars->map.points_matrix)
	{
		if (vars->map.points_matrix[0] != NULL)
			free(vars->map.points_matrix[0]);
		free(vars->map.points_matrix);
	}
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->window)
		mlx_destroy_window(vars->mlx, vars->window);
	if (vars->mlx)
	{
		clean_mlx(vars->mlx);
	}
	exit(0);
	return (0);
}
