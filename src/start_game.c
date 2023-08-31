/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:56:48 by ancolmen          #+#    #+#             */
/*   Updated: 2023/03/14 15:21:59 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
This function will start the mlx, create a new window, draw the static images 
on the map + the moves and start the game loop. It will handle also the key 
and mouse events as well as the updating
*/
void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exit(game);
	game->win = mlx_new_window(game->mlx, game->lay.col * IS,
			(game->lay.row * IS) + 64, "This is SO LONG!");
	if (!game->win)
		ft_exit(game);
	load_all_xpm(game);
	render_map(game);
	render_moves(game);
	mlx_hook(game->win, 17, (1L << 0), ft_exit, (void *)game);
	mlx_key_hook(game->win, key_event_handler, (void *)game);
	mlx_loop_hook(game->mlx, update_game, (void *)game);
	mlx_loop(game->mlx);
}

/*
This function will update the images at each loop
*/
int	update_game(t_game *game)
{
	game->n_loops += 1;
	if (!game->death && !game->won)
	{
		render_player(game);
		update_enemy(game);
	}
	return (0);
}
