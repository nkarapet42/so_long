/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:58:40 by nkarapet          #+#    #+#             */
/*   Updated: 2024/01/26 15:58:43 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include "../mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif
# define SIZE 60
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_img
{
	void	*coin;
	void	*rcoin;
	void	*e;
	void	*exit;
	void	*open;
	void	*p;
	void	*player;
	void	*rplayer;
	void	*grass;
	void	*walls;
	void	*monster;
	void	*mlx;
	void	*win;
}	t_img;

typedef struct s_map
{
	char		**mapi;
	t_player	player;
	int			n;
	int			m;
	int			coins;
}	t_map;

typedef struct s_game
{
	t_map	map;
	t_img	xpm;
	int		w;
	int		h;
	int		steps;
}	t_game;

void		free_str(char **dest, int i);
void		flood_fill_recursive(char **tab, t_map *map,
				t_player current, char target);
void		ft_get_image(t_game *game);
int			frame(t_game *game);
void		move_w(t_game *game);
void		move_s(t_game *game);
void		move_a(t_game *game);
void		move_d(t_game *game);
void		exit_game(t_game *game, int out);
void		ft_steps(t_game *game);
int			press(t_game *game);
int			ft_printmap(t_game *game, void *anim);
void		ft_printmap2(t_game *game, int i, int j);
void		ft_printmap1(t_game *game, void *anim, int i, int j);
int			keyword(int key, t_game *game);
void		flood_fill(t_map *map);
char		*get_next_line(int fd);
int			ft_strlen(const char *s);
char		*ft_strchr(const char *str, int argument);
size_t		ft_strlcpy(char *dest, const char *src, size_t destsize);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strtrim2(char *s1, char *set);
void		check_newline(char *join);
char		*check_newline2(char *join);
void		check_whitespaces(char **res);
char		*ft_strdup(char *src);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		**ft_pars(int fd);
void		ft_validation(t_map *map);
void		ft_other(t_map *map);
void		ft_chwalls(t_map *map);
void		ft_sidewalls(t_map *map);
void		ft_collectibals(t_map *map);
void		ft_waycheck(char **tab);
int			coin_count(t_map *map);
void		player_count(t_map *map);
void		exit_count(t_map *map);
void		find_player(t_map *map);
void		ft_start(t_map *map);

#endif