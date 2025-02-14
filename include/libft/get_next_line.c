/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:17:14 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/03 11:42:31 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

static int	check_fd(int fd, char **remainder)
{
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
	{
		if (remainder != NULL)
			ft_free(remainder);
		return (0);
	}
	return (1);
}

static char	*handle_remainder(char *current, char **remainder)
{
	size_t	len;
	size_t	len_nl;
	char	*result;

	result = NULL;
	len = ft_strlen(current);
	if (len == 0)
		return (ft_free(&current));
	len_nl = ft_strlen_nl(current);
	if (len != len_nl)
	{
		*remainder = ft_substr(current, len_nl + 1, len - len_nl - 1);
		if (*remainder == NULL)
			return (ft_free(&current));
		result = ft_substr(current, 0, len_nl + 1);
		if (result == NULL)
		{
			ft_free(remainder);
			return (ft_free(&current));
		}
		ft_free(&current);
	}
	if (current != NULL)
		return (current);
	return (result);
}

static char	*read_line(int fd, char *result)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	ssize_t	check;

	while (ft_strchr(result, '\n') == 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
			return (NULL);
		if (check == 0)
			break ;
		buffer[check] = '\0';
		temp = result;
		result = ft_strjoin(result, buffer);
		ft_free(&temp);
		if (result == NULL)
			return (NULL);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char		*remainder;
	char			*line;

	if (check_fd(fd, &remainder) == 0)
		return (NULL);
	line = NULL;
	if (remainder != NULL)
	{
		line = ft_strjoin(line, remainder);
		ft_free(&remainder);
		if (line == NULL)
			return (NULL);
	}
	line = read_line(fd, line);
	if (line == NULL)
	{
		if (remainder != NULL)
			ft_free(&remainder);
		return (ft_free(&line));
	}
	line = handle_remainder(line, &remainder);
	return (line);
}
