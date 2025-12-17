/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:13:14 by pserre-s          #+#    #+#             */
/*   Updated: 2025/12/17 17:38:54 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static int	is_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i >= 2);
}

static int	get_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	base_len;
	int	val;

	if (!is_base_valid(base))
		return (0);
	base_len = 0;
	while (base[base_len])
		base_len++;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	result = 0;
	val = get_value(str[i]);
	while (val != -1)
	{
		result = result * base_len + val;
		i++;
		val = get_value(str[i]);
	}
	return (result * sign);
}
