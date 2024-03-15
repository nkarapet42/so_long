/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:09:51 by nkarapet          #+#    #+#             */
/*   Updated: 2024/01/31 16:09:54 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

static void	free_ptr(char **str)
{
	free(*str);
	*str = NULL;
}

static char	*get_line(char **buff_b, char **line)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	while (*(*buff_b + i) != '\n' && *(*buff_b + i) != '\0')
		i++;
	if (*(*buff_b + i) == '\n')
	{
		i++;
		*line = ft_substr(*buff_b, 0, i);
		res = ft_strdup(*buff_b + i);
	}
	else
		*line = ft_strdup(*buff_b);
	free_ptr(buff_b);
	return (res);
}

static char	read_line(int fd, char **buff, char **buff_b, char **line)
{
	int		byte;
	char	*temp;

	byte = 1;
	while (!ft_strchr(*buff_b, '\n') && byte)
	{
		byte = read(fd, *buff, BUFFER_SIZE);
		(*buff)[byte] = '\0';
		temp = *buff_b;
		*buff_b = ft_strjoin(temp, *buff);
		if (!buff_b)
			return (0);
		free(temp);
	}
	free_ptr(buff);
	*buff_b = get_line(buff_b, line);
	if (!(**line))
		free_ptr(line);
	return (byte);
}

char	*get_next_line(int fd)
{
	static char	*buffers = NULL;
	char		*buff;
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (read(fd, buff, 0) < 0)
	{
		free(buff);
		return (NULL);
	}
	if (!buffers)
		buffers = ft_strdup("");
	if (!read_line(fd, &buff, &buffers, &line) && !line)
		return (NULL);
	return (line);
}
