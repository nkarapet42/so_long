/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:12:43 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/17 12:12:46 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	move_w(t_game *game)
{
	if (game->map.mapi[game->map.player.y - 1][game->map.player.x] != '1')
	{
		if (game->map.mapi[game->map.player.y - 1][game->map.player.x] == 'A')
			exit_game(game, 0);
		if (game->map.mapi[game->map.player.y - 1][game->map.player.x] == 'C')
		{
			game->map.mapi[game->map.player.y - 1][game->map.player.x] = '0';
			game->map.coins -= 1;
		}
		if (game->map.mapi[game->map.player.y - 1][game->map.player.x] == 'E')
		{
			if (game->xpm.e == game->xpm.open)
				exit_game(game, 1);
		}
		game->steps += 1;
		game->map.player.y -= 1;
	}
}

void	move_s(t_game *game)
{
	if (game->map.mapi[game->map.player.y + 1][game->map.player.x] != '1')
	{
		if (game->map.mapi[game->map.player.y + 1][game->map.player.x] == 'A')
			exit_game(game, 0);
		if (game->map.mapi[game->map.player.y + 1][game->map.player.x] == 'C')
		{
			game->map.mapi[game->map.player.y + 1][game->map.player.x] = '0';
			game->map.coins -= 1;
		}
		if (game->map.mapi[game->map.player.y + 1][game->map.player.x] == 'E')
		{
			if (game->xpm.e == game->xpm.open)
				exit_game(game, 1);
		}
		game->steps += 1;
		game->map.player.y += 1;
	}
}

void	move_a(t_game *game)
{
	game->xpm.p = game->xpm.rplayer;
	if (game->map.mapi[game->map.player.y][game->map.player.x - 1] != '1')
	{
		if (game->map.mapi[game->map.player.y][game->map.player.x - 1] == 'A')
			exit_game(game, 0);
		if (game->map.mapi[game->map.player.y][game->map.player.x - 1] == 'C')
		{
			game->map.mapi[game->map.player.y][game->map.player.x - 1] = '0';
			game->map.coins -= 1;
		}
		if (game->map.mapi[game->map.player.y][game->map.player.x - 1] == 'E')
		{
			if (game->xpm.e == game->xpm.open)
				exit_game(game, 1);
		}
		game->steps += 1;
		game->map.player.x -= 1;
	}
}

void	move_d(t_game *game)
{
	game->xpm.p = game->xpm.player;
	if (game->map.mapi[game->map.player.y][game->map.player.x + 1] != '1')
	{
		if (game->map.mapi[game->map.player.y][game->map.player.x + 1] == 'A')
			exit_game(game, 0);
		if (game->map.mapi[game->map.player.y][game->map.player.x + 1] == 'C')
		{
			game->map.mapi[game->map.player.y][game->map.player.x + 1] = '0';
			game->map.coins -= 1;
		}
		if (game->map.mapi[game->map.player.y][game->map.player.x + 1] == 'E')
		{
			if (game->xpm.e == game->xpm.open)
				exit_game(game, 1);
		}
		game->steps += 1;
		game->map.player.x += 1;
	}
}
