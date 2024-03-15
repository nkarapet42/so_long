/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:10:13 by nkarapet          #+#    #+#             */
/*   Updated: 2024/01/31 16:10:15 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	free_str(char **dest, int i)
{
	while (i > 0)
	{
		free(dest[i - 1]);
		i--;
	}
	free(dest);
	dest = NULL;
}

char	**ft_pars(int fd)
{
	char	**res;
	char	*temp;
	char	*join;
	char	*temp1;

	join = ft_strdup("");
	if (!join)
		exit (0);
	temp = get_next_line(fd);
	while (temp)
	{
		temp1 = join;
		join = ft_strjoin(join, temp);
		free(temp1);
		free(temp);
		temp = get_next_line(fd);
	}
	join = check_newline2(join);
	check_newline(join);
	res = ft_split(join, '\n');
	check_whitespaces(res);
	free (join);
	return (res);
}

static char	**ft_mapcpy(t_map *map, int i)
{
	int		j;
	char	**dest;

	dest = (char **)malloc((map->n + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	while (i < map->n)
	{
		j = 0;
		dest[i] = (char *)malloc((map->m + 1) * sizeof(char));
		if (!dest[i])
		{
			free_str(dest, i);
			return (NULL);
		}
		while (j < map->m)
		{
			dest[i][j] = map->mapi[i][j];
			j++;
		}
		dest[i][j] = '\0';
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

void	flood_fill_recursive(char **tab, t_map *map,
t_player current, char target)
{
	if (tab[current.y][current.x] == 'C' || tab[current.y][current.x] == 'E')
		tab[current.y][current.x] = '0';
	if (tab[current.y][current.x] != target)
		return ;
	tab[current.y][current.x] = 'F';
	flood_fill_recursive(tab, map,
		(t_player){current.x - 1, current.y}, target);
	flood_fill_recursive(tab, map,
		(t_player){current.x + 1, current.y}, target);
	flood_fill_recursive(tab, map,
		(t_player){current.x, current.y - 1}, target);
	flood_fill_recursive(tab, map,
		(t_player){current.x, current.y + 1}, target);
	return ;
}

void	flood_fill(t_map *map)
{
	char		target;
	char		**tab;
	int			i;
	t_player	begin;

	i = 0;
	tab = ft_mapcpy(map, i);
	if (!tab)
		exit(0);
	begin.y = map->player.y;
	begin.x = map->player.x;
	target = '0';
	tab[begin.y][begin.x] = target;
	flood_fill_recursive(tab, map, begin, target);
	ft_waycheck(tab);
	free_str(tab, map->n);
}
