/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:42:50 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/17 12:42:53 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	press(t_game *game)
{
	exit_game(game, -1);
	return (0);
}

void	exit_game(t_game *game, int out)
{
	if (out == 1)
		write(1, "GRACES!!!\n", 10);
	else if (out == 0)
		write(1, "GAME OVER :(\n", 13);
	mlx_destroy_image(game->xpm.mlx, game->xpm.coin);
	mlx_destroy_image(game->xpm.mlx, game->xpm.rcoin);
	mlx_destroy_image(game->xpm.mlx, game->xpm.e);
	mlx_destroy_image(game->xpm.mlx, game->xpm.p);
	mlx_destroy_image(game->xpm.mlx, game->xpm.walls);
	mlx_destroy_image(game->xpm.mlx, game->xpm.monster);
	mlx_destroy_image(game->xpm.mlx, game->xpm.grass);
	free_str(game->map.mapi, game->map.n);
	exit(0);
}
