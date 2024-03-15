/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:42:18 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/01 18:42:20 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	ft_validation(t_map *map)
{
	int		i;
	int		n;

	n = 0;
	while (map->mapi[n])
		n++;
	map->n = n;
	map->m = ft_strlen(map->mapi[0]);
	i = 1;
	while (map->mapi[i])
	{
		if (map->m != ft_strlen(map->mapi[i]))
		{
			write(2, "Invalid map, use another one!\n", 30);
			exit(0);
		}
		i++;
	}
	ft_other(map);
	ft_chwalls(map);
}

void	ft_other(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->n)
	{
		j = 0;
		while (j < map->m)
		{
			if (map->mapi[i][j] != '1' && map->mapi[i][j] != '0'
				&& map->mapi[i][j] != 'P' && map->mapi[i][j] != 'E'
				&& map->mapi[i][j] != 'A' && map->mapi[i][j] != 'C')
			{
				write (2, "There is undefined object\n", 26);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	ft_chwalls(t_map *map)
{
	int		j;

	j = 0;
	while (map->mapi[0][j] || map->mapi[map->n - 1][j])
	{
		if (map->mapi[0][j] != '1' || map->mapi[map->n - 1][j] != '1')
		{
			write(2, "Invalid map, use another one!\n", 30);
			exit(0);
		}
		j++;
	}
	ft_sidewalls(map);
}

void	ft_sidewalls(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->n)
	{
		if (map->mapi[i][0] != '1' || map->mapi[i][map->m - 1] != '1')
		{
			write(2, "Invalid map, use another one!\n", 30);
			exit(0);
		}
		i++;
	}
	ft_collectibals(map);
}

void	ft_waycheck(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C' || tab[i][j] == 'E')
			{
				write (2, "Can't reach to exit!\n", 21);
				exit(0);
			}
			j++;
		}
		i++;
	}
}
