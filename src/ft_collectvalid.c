/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectvalid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:16:34 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/02 17:16:36 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	ft_collectibals(t_map *map)
{
	map->coins = coin_count(map);
	player_count(map);
	exit_count(map);
	find_player(map);
	flood_fill(map);
}

int	coin_count(t_map *map)
{
	int		i;
	int		j;
	int		count;

	i = 1;
	count = 0;
	while (i < map->n)
	{
		j = 1;
		while (j < map->m)
		{
			if (map->mapi[i][j] == 'C')
				count += 1;
			j++;
		}
		i++;
	}
	if (count < 1)
	{
		write(2, "There is no coins in the map\n", 29);
		exit(0);
	}
	return (count);
}

void	exit_count(t_map *map)
{
	int		i;
	int		j;
	int		count;

	i = 1;
	count = 0;
	while (i < map->n)
	{
		j = 1;
		while (j < map->m)
		{
			if (map->mapi[i][j] == 'E')
				count += 1;
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		write(2, "Incorrect number of Exit\n", 25);
		exit(0);
	}
}

void	player_count(t_map *map)
{
	int		i;
	int		j;
	int		count;

	i = 1;
	count = 0;
	while (i < map->n)
	{
		j = 1;
		while (j < map->m)
		{
			if (map->mapi[i][j] == 'P')
				count += 1;
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		write(2, "Incorrect number of Player\n", 27);
		exit(0);
	}
}

void	find_player(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->n)
	{
		j = 1;
		while (map->mapi[i][j])
		{
			if (map->mapi[i][j] == 'P')
			{
				map->player.y = i;
				map->player.x = j;
			}
			j++;
		}
		i++;
	}
}
