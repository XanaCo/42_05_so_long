/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:27:31 by ancolmen          #+#    #+#             */
/*   Updated: 2023/02/27 20:47:04 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
This function will draw the north walls on the map
*/
void	render_wall_n(t_game *game, t_point crd)
{
	if (crd.y == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->fix.w_nw,
			crd.y, crd.x);
	else if (crd.y == ((int)game->lay.col * IS) - IS)
		mlx_put_image_to_window(game->mlx, game->win, game->fix.w_ne,
			crd.y, crd.x);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->fix.w_n,
			crd.y, crd.x);
}

/*
This function will draw the south walls on the map
*/
void	render_wall_s(t_game *game, t_point crd)
{
	if (crd.y == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->fix.w_sw,
			crd.y, crd.x);
	else if (crd.y == ((int)game->lay.col * IS) - IS)
		mlx_put_image_to_window(game->mlx, game->win, game->fix.w_se,
			crd.y, crd.x);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->fix.w_s,
			crd.y, crd.x);
}

/*
This function will draw the moves on the screen, 
taken from the struct counter
*/
void	render_moves(t_game *game)
{
	int	h;
	int	t;
	int	u;

	h = (game->mov / 100);
	t = (game->mov % 100) / 10;
	u = (game->mov % 100) % 10;
	mlx_put_image_to_window(game->mlx, game->win, game->dig[h].img,
		((game->lay.col / 2) * IS) - 96, game->lay.row * IS);
	mlx_put_image_to_window(game->mlx, game->win, game->dig[t].img,
		((game->lay.col / 2) * IS) - 32, game->lay.row * IS);
	mlx_put_image_to_window(game->mlx, game->win, game->dig[u].img,
		((game->lay.col / 2) * IS) + 32, game->lay.row * IS);
}
