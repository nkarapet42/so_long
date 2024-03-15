/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:10:19 by nkarapet          #+#    #+#             */
/*   Updated: 2024/01/31 16:10:22 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	if (argc < 2 || argc > 2)
		return (write(2, "Invalid count of arguments\n", 27));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "Can't read file.\n", 17));
	map.mapi = ft_pars(fd);
	if (!map.mapi[0])
	{
		write(2, "There isn't map!\n", 17);
		return (0);
	}
	ft_validation(&map);
	ft_start(&map);
	return (0);
}
