/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:51:47 by pserre-s          #+#    #+#             */
/*   Updated: 2025/12/18 13:15:13 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_variables(t_var *vars)
{
	ft_bzero(vars, sizeof(t_var));

	vars->zoom = DEFAULT_ZOOM;
	vars->x_offset = X_LEN / 2;
	vars->y_offset = Y_LEN / 3;

	vars->z_scale = 1.0;
	vars->angle_x = 0.0;
	vars->angle_x = 0.0;
}


