/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:42:48 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/17 11:42:53 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	ft_steps(t_game *game)
{
	char	*str;

	str = ft_itoa(game->steps);
	mlx_string_put(game->xpm.mlx, game->xpm.win, (game->map.m - 2) * SIZE,
		0, 0x0, str);
	free(str);
}

void	ft_printmap2(t_game *game, int i, int j)
{
	if (game->map.mapi[i][j] == '1')
		mlx_put_image_to_window(game->xpm.mlx, game->xpm.win,
			game->xpm.walls, j * SIZE, i * SIZE);
	else if (game->map.mapi[i][j] == 'A')
		mlx_put_image_to_window(game->xpm.mlx, game->xpm.win,
			game->xpm.monster, j * SIZE, i * SIZE);
}

void	ft_printmap1(t_game *game, void *anim, int i, int j)
{
	mlx_put_image_to_window(game->xpm.mlx, game->xpm.win,
		game->xpm.p, game->map.player.x * SIZE,
		game->map.player.y * SIZE);
	if (game->map.mapi[i][j] == 'E')
		mlx_put_image_to_window(game->xpm.mlx, game->xpm.win,
			game->xpm.e, j * SIZE, i * SIZE);
	else if (game->map.mapi[i][j] == 'C')
		mlx_put_image_to_window(game->xpm.mlx, game->xpm.win,
			anim, j * SIZE, i * SIZE);
}

int	ft_printmap(t_game *game, void *anim)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.n)
	{
		j = 0;
		while (j < game->map.m)
		{
			mlx_put_image_to_window(game->xpm.mlx, game->xpm.win,
				game->xpm.grass, j * SIZE, i * SIZE);
			ft_printmap1(game, anim, i, j);
			ft_printmap2(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
