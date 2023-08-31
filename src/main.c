/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:13:28 by anana             #+#    #+#             */
/*   Updated: 2023/02/27 22:20:51 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game = game_init();
	if (argc != 2)
		map_error("Invalid number of arguments!\n", &game);
	game.map.fd = open(argv[1], O_RDONLY);
	if (game.map.fd < 0)
		map_error("File not found!\n", &game);
	if (ft_strrncmp(argv[1], ".ber", 4))
		map_error("Your map has the wrong format!\n", &game);
	game.map.map = check_map(&game);
	start_game(&game);
	close(game.map.fd);
	return (0);
}
