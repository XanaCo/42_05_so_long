/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_p_anim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:27:31 by ancolmen          #+#    #+#             */
/*   Updated: 2023/02/27 20:34:52 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
This function will draw the player on the window, depending on its 
looking direction
*/
void	render_player(t_game *game)
{
	if (game->dir == 0)
		render_pl_r(game);
	if (game->dir == 1)
		render_pl_l(game);
}

/*
This function will draw the player looking right
*/
void	render_pl_r(t_game *game)
{
	if (game->n_loops <= RATE)
		mlx_put_image_to_window(game->mlx, game->win, game->pl_r.img1,
			game->plpos.y * IS, game->plpos.x * IS);
	else if (game->n_loops <= RATE * 2)
		mlx_put_image_to_window(game->mlx, game->win, game->pl_r.img2,
			game->plpos.y * IS, game->plpos.x * IS);
	else if (game->n_loops <= RATE * 3)
		mlx_put_image_to_window(game->mlx, game->win, game->pl_r.img3,
			game->plpos.y * IS, game->plpos.x * IS);
	else if (game->n_loops <= RATE * 4)
		mlx_put_image_to_window(game->mlx, game->win, game->pl_r.img4,
			game->plpos.y * IS, game->plpos.x * IS);
	if (game->n_loops > RATE * 4)
	{
		game->n_loops = 0;
		render_player(game);
	}
}

/*
This function will draw the player looking left
*/
void	render_pl_l(t_game *game)
{
	if (game->n_loops <= RATE)
		mlx_put_image_to_window(game->mlx, game->win, game->pl_l.img1,
			game->plpos.y * IS, game->plpos.x * IS);
	else if (game->n_loops <= RATE * 2)
		mlx_put_image_to_window(game->mlx, game->win, game->pl_l.img2,
			game->plpos.y * IS, game->plpos.x * IS);
	else if (game->n_loops <= RATE * 3)
		mlx_put_image_to_window(game->mlx, game->win, game->pl_l.img3,
			game->plpos.y * IS, game->plpos.x * IS);
	else if (game->n_loops <= RATE * 4)
		mlx_put_image_to_window(game->mlx, game->win, game->pl_l.img4,
			game->plpos.y * IS, game->plpos.x * IS);
	if (game->n_loops > RATE * 4)
	{
		game->n_loops = 0;
		render_player(game);
	}
}
