/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:27:31 by ancolmen          #+#    #+#             */
/*   Updated: 2023/02/27 17:26:39 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
This function will parse the map and draw the different fix tiles 
(non-moving xpms, before the game loop)
*/
void	render_map(t_game *game)
{
	t_point	crd;

	crd.x = 0;
	while (crd.x < ((int)game->lay.row * IS))
	{
		crd.y = 0;
		while (crd.y < ((int)game->lay.col * IS))
		{
			if (game->map.map[crd.x / IS][crd.y / IS] == '0')
				render_floor(game, crd);
			if (game->map.map[crd.x / IS][crd.y / IS] == '1')
				render_wall(game, crd);
			if (game->map.map[crd.x / IS][crd.y / IS] == 'E')
				render_exit(game, crd);
			if (game->map.map[crd.x / IS][crd.y / IS] == 'C')
				render_col(game, crd);
			if (game->map.map[crd.x / IS][crd.y / IS] == 'X')
			{
				stock_enemy(game, crd);
				render_en_r(game, crd);
			}
			crd.y += IS;
		}
		crd.x += IS;
	}
}

/*
This function will draw the wall tiles, depending on their position
*/
void	render_wall(t_game *game, t_point crd)
{
	if (crd.x == 0)
		render_wall_n(game, crd);
	else if (crd.x == ((int)game->lay.row * IS) - IS)
		render_wall_s(game, crd);
	else if (crd.y == ((int)game->lay.col * IS) - IS)
		mlx_put_image_to_window(game->mlx, game->win, game->fix.w_ew,
			crd.y, crd.x);
	else if (crd.y == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->fix.w_ew,
			crd.y, crd.x);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->fix.w_t,
			crd.y, crd.x);
}

/*
This function will draw the collectibles
*/
void	render_col(t_game *game, t_point crd)
{
	mlx_put_image_to_window(game->mlx, game->win, game->fix.col, crd.y, crd.x);
}

/*
This function will draw the floor
*/
void	render_floor(t_game *game, t_point crd)
{
	mlx_put_image_to_window(game->mlx, game->win, game->fix.fl, crd.y, crd.x);
}

/*
This function will draw the exit tile, and will be called if needed in the loop
*/
void	render_exit(t_game *game, t_point crd)
{
	game->epos.x = crd.x;
	game->epos.y = crd.y;
	if (game->exit)
		mlx_put_image_to_window(game->mlx, game->win, game->fix.ex,
			crd.y, crd.x);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->fix.n_ex,
			crd.y, crd.x);
}
