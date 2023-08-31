/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:53:48 by ancolmen          #+#    #+#             */
/*   Updated: 2023/03/17 15:29:12 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
This function will manage all key events
*/
int	key_event_handler(int keycode, t_game *game)
{
	if (keycode == ESC || keycode == QUIT)
		ft_exit(game);
	if (game->death || game->won)
		return (0);
	else if (keycode == UP || keycode == W)
		update_player(game, game->plpos.x - 1, game->plpos.y);
	else if (keycode == DOWN || keycode == S)
		update_player(game, game->plpos.x + 1, game->plpos.y);
	else if (keycode == LEFT || keycode == A)
	{
		game->dir = 1;
		update_player(game, game->plpos.x, game->plpos.y - 1);
	}
	else if (keycode == RIGHT || keycode == D)
	{
		game->dir = 0;
		update_player(game, game->plpos.x, game->plpos.y + 1);
	}
	return (0);
}

/*
This function will update the player according to the key event and its position 
*/
void	update_player(t_game *game, int x, int y)
{
	if (game->map.map[x][y] == 'C')
	{
		game->lay_cpy.collect++;
		game->map.map[x][y] = '0';
		if (game->lay_cpy.collect == game->lay.collect)
		{
			game->exit = 1;
			render_exit(game, game->epos);
		}
	}	
	if (game->map.map[x][y] == 'E' && game->exit)
	{
		render_won(game);
		return ;
	}
	if (game->map.map[x][y] == 'X')
	{
		render_death(game);
		return ;
	}
	if (game->map.map[x][y] == '0' || game->map.map[x][y] == 'P')
		player_move(game, x, y);
	ft_printf("Total moves : %d\n", game->mov);
	render_moves(game);
}

/*
This function will draw the floor behind the player updating its position
*/
void	player_move(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->fix.fl,
		game->plpos.y * IS, game->plpos.x * IS);
	game->plpos.x = x;
	game->plpos.y = y;
	game->mov += 1;
}

/*
This function will draw the little death tomb fot the player
*/
void	render_death(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->fix.die,
		game->plpos.y * IS, game->plpos.x * IS);
	game->death = 1;
	ft_printf("GAME OVER...\n");
}

/*
This function will put the 'you won' image into the window, centering it 
*/
void	render_won(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->fix.y_w,
		(-1920 / 2) + ((game->lay.col / 2) * IS), (-1024 / 2)
		+ ((game->lay.row / 2) * IS));
	game->won = 1;
	ft_printf("YOU WON!\n");
}
