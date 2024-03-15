/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:10:41 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/12 14:10:44 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	ft_start(t_map *map)
{
	t_game	game;

	game.map = *map;
	game.xpm.mlx = mlx_init();
	game.xpm.win = mlx_new_window(game.xpm.mlx, game.map.m * 60,
			game.map.n * 60, "GAME");
	ft_get_image(&game);
	game.xpm.p = game.xpm.player;
	game.xpm.e = game.xpm.exit;
	game.steps = 0;
	mlx_hook(game.xpm.win, 2, 0, &keyword, &game);
	mlx_loop_hook(game.xpm.mlx, &frame, &game);
	mlx_hook(game.xpm.win, 17, 0, &press, &game);
	mlx_loop(game.xpm.mlx);
}

void	*side(t_game *game)
{
	static int	i = 0;
	static void	*anim = NULL;

	if (i % 25 == 0)
		anim = game->xpm.coin;
	if (i % 50 == 0)
		anim = game->xpm.rcoin;
	i++;
	return (anim);
}

int	frame(t_game *game)
{
	void	*anim;

	anim = side(game);
	if (game->map.coins == 0)
		game->xpm.e = game->xpm.open;
	mlx_clear_window(game->xpm.mlx, game->xpm.win);
	ft_printmap(game, anim);
	ft_steps(game);
	return (0);
}

int	keyword(int key, t_game *game)
{
	if (key == ESC)
		exit_game(game, -1);
	else if (key == W)
		move_w(game);
	else if (key == S)
		move_s(game);
	else if (key == A)
		move_a(game);
	else if (key == D)
		move_d(game);
	return (0);
}

void	ft_get_image(t_game *game)
{
	game->w = SIZE;
	game->h = SIZE;
	game->xpm.coin = mlx_xpm_file_to_image(game->xpm.mlx, "xpm/Coins.xpm",
			&game->w, &game->h);
	game->xpm.rcoin = mlx_xpm_file_to_image(game->xpm.mlx, "xpm/Rcoins.xpm",
			&game->w, &game->h);
	game->xpm.player = mlx_xpm_file_to_image(game->xpm.mlx, "xpm/Player.xpm",
			&game->w, &game->h);
	game->xpm.rplayer = mlx_xpm_file_to_image(game->xpm.mlx, "xpm/Rplayer.xpm",
			&game->w, &game->h);
	game->xpm.exit = mlx_xpm_file_to_image(game->xpm.mlx, "xpm/Exit.xpm",
			&game->w, &game->h);
	game->xpm.open = mlx_xpm_file_to_image(game->xpm.mlx, "xpm/Open.xpm",
			&game->w, &game->h);
	game->xpm.grass = mlx_xpm_file_to_image(game->xpm.mlx, "xpm/Grass.xpm",
			&game->w, &game->h);
	game->xpm.walls = mlx_xpm_file_to_image(game->xpm.mlx, "xpm/Walls.xpm",
			&game->w, &game->h);
	game->xpm.monster = mlx_xpm_file_to_image(game->xpm.mlx, "xpm/Monster.xpm",
			&game->w, &game->h);
}
