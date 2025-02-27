/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:52:59 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/02/27 13:51:30 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	validate_map_line(char *line)
{
	size_t	len;

	len = 0;
	while (line[len] != '\n' && line[len] != '\0')
	{
		if (line[len] == ' ' || line[len] == '1' || line[len] == '0')
			len++;
		else if (line[len] == 'N' || line[len] == 'E' || \
			line[len] == 'S' || line[len] == 'W')
			len++;
		else
			return (0);
	}
	return (len);
}

int	validate_space(char *line)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen_nl(line);
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == '0')
		{
			if (i == 0 || i == len)
				return (-1);
			else if (line[i - 1] == ' ' || line[i + 1] == ' ')
				return (-1);
			else
				i++;
		}
		else
			i++;
	}
	return (1);
}

int	check_walls(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '1')
			i++;
		else
			return (-1);
	}
	return (1);
}
