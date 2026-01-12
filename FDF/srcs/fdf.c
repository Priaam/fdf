/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 02:43:38 by pserre-s          #+#    #+#             */
/*   Updated: 2026/01/12 01:33:30 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	fdf_main_loop(t_var *vars)
{
	fdf_update_movement(vars);
	fdf_draw_map(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	vars;

	if (argc == 2)
	{
		fdf_init_variables(&vars);
		parsing_map(argv[1], &vars);
		if (((double)X_LEN / vars.map.width)
			< ((double)Y_LEN / vars.map.height))
			vars.zoom = ((double)X_LEN / vars.map.width) * 0.45;
		else
			vars.zoom = ((double)Y_LEN / vars.map.height) * 0.45;
		if (vars.zoom < 1)
			vars.zoom = 1;
		if (init_mlx(&vars) == 1)
		{
			fdf_error_exit("Erreur d'initialisation des variables.");
		}
		fdf_draw_map(&vars);
		setup_hooks(&vars);
		mlx_loop(vars.mlx);
		return (0);
	}
	return (ft_printf("Un seul argument possible (./fdf <map.fdf>)"), 1);
}
