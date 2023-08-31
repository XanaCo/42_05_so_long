/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:54:26 by ancolmen          #+#    #+#             */
/*   Updated: 2023/02/27 20:26:35 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
This function will clean the map parsing and checking part, 
it will call end_game if needed and exit
*/
int	ft_exit(t_game *game)
{
	if (game->map.big_line)
		free(game->map.big_line);
	if (game->map.last_line)
		free(game->map.last_line);
	if (game->map.map)
		ft_free_matrix(game->map.map);
	if (game->map.map_cpy)
		ft_free_matrix(game->map.map_cpy);
	if (game->mlx)
		end_game(game);
	exit(0);
}

/*
This function will call all freeing functions and 
will destroy all windows ands displays, freeing mlx pointer
*/
void	end_game(t_game	*game)
{
	free_img_fix(game);
	free_events(game);
	free_anim(game);
	mlx_clear_window (game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

/*
This function will call all anim destroying functions
*/
void	free_anim(t_game *game)
{
	free_player(game);
	free_enemy(game);
	free_digits(game);
	free_col(game);
	free_list(game->en);
}

/*
This function will destroy the fix images on fix struct
*/
void	free_img_fix(t_game *game)
{
	if (game->fix.fl)
		mlx_destroy_image(game->mlx, game->fix.fl);
	if (game->fix.w_n)
		mlx_destroy_image(game->mlx, game->fix.w_n);
	if (game->fix.w_s)
		mlx_destroy_image(game->mlx, game->fix.w_s);
	if (game->fix.w_ew)
		mlx_destroy_image(game->mlx, game->fix.w_ew);
	if (game->fix.w_ne)
		mlx_destroy_image(game->mlx, game->fix.w_ne);
	if (game->fix.w_nw)
		mlx_destroy_image(game->mlx, game->fix.w_nw);
	if (game->fix.w_se)
		mlx_destroy_image(game->mlx, game->fix.w_se);
	if (game->fix.w_sw)
		mlx_destroy_image(game->mlx, game->fix.w_sw);
	if (game->fix.w_t)
		mlx_destroy_image(game->mlx, game->fix.w_t);
	if (game->fix.ex)
		mlx_destroy_image(game->mlx, game->fix.ex);
	if (game->fix.n_ex)
		mlx_destroy_image(game->mlx, game->fix.n_ex);
	if (game->fix.col)
		mlx_destroy_image(game->mlx, game->fix.col);
}

/*
This function will destroy the event images on fix struct
*/
void	free_events(t_game *game)
{
	if (game->fix.y_w)
		mlx_destroy_image(game->mlx, game->fix.y_w);
	if (game->fix.die)
		mlx_destroy_image(game->mlx, game->fix.die);
}
