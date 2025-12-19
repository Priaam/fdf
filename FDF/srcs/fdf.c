/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 02:43:38 by pserre-s          #+#    #+#             */
/*   Updated: 2025/12/19 20:56:14 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_screen(t_var *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < Y_LEN)
	{
		x = 0;
		while (x < X_LEN)
		{
			my_pixel_put(&data->img, x, y, color);
			x++;
		}
		y++;
	}
}

static int	init_mlx(t_var *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (1);
	vars->window = mlx_new_window(vars->mlx, X_LEN, Y_LEN, "Fil de fer");
	if (!vars->window)
	{
		return (1);
	}
	vars->img.img = mlx_new_image(vars->mlx, X_LEN, Y_LEN);
	if (!vars->img.img)
	{
		return (1);
	}
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_len, &vars->img.endian);
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	vars;

	if (argc == 2)
	{
		fdf_init_variables(&vars);
		parsing_map(argv[1], &vars);
		if (init_mlx(&vars) == 1)
		{
			close_window(&vars);
			return (1);
		}
		fdf_draw_map(&vars);
		setup_hooks(&vars);
		mlx_loop(vars.mlx);
		return (0);
	}
	return (ft_printf("Un seul argument possible (./fdf <map.fdf>)"), 1);
}
