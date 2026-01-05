/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:53:03 by pserre-s          #+#    #+#             */
/*   Updated: 2026/01/05 14:42:01 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init_variables(t_var *vars)
{
	ft_bzero(vars, sizeof(t_var));
	vars->zoom = DEFAULT_ZOOM;
	vars->x_offset = X_LEN / 2;
	vars->y_offset = Y_LEN / 3;
	vars->z_scale = 1;
	vars->angle_x = 0.0;
	vars->angle_x = 0.0;
}

void	fdf_error_exit(char *msg)
{
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

int	fdf_is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	fdf_get_color(char *s)
{
	char	*comma;
	char	*hexa_code;

	comma = ft_strchr(s, ',');
	if (comma && comma[1])
	{
		hexa_code = comma + 1;
		if (hexa_code[0] == '0'
			&& (hexa_code[1] == 'x' || hexa_code[1] == 'X'))
			return (ft_atoi_base(hexa_code + 2, "0123456789abcdef"));
	}
	return (DEFAULT_COLOR);
}

int	fdf_check_extension(const char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename || ft_strncmp(dot, ".fdf", 5) != 0)
		return (0);
	return (1);
}
