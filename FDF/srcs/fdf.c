/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 02:43:38 by pserre-s          #+#    #+#             */
/*   Updated: 2025/12/16 13:19:41 by pserre-s         ###   ########.fr       */
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

int	fun(int key, t_var *data)
{
	if (key == K_LEFT)
		color_screen(data, 0xff0000);
	else if (key == K_RIGHT)
		color_screen(data, 0x00ff00);
	else if (key == K_UP)
		color_screen(data, 0x0000ff);
	else if (key == K_ESC)
		close_window(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img.img, 0, 0);
	return (0);
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

	ft_bzero(&vars, sizeof(t_var));
	if (init_mlx(&vars) == 1)
	{
		close_window(&vars);
		return (1);
	}
	setup_hooks(&vars);
	parsing_map(argv[1], &vars);
	mlx_loop(vars.mlx);
	(void)argc;
	return (0);
}
