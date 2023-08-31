/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_e_anim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:27:31 by ancolmen          #+#    #+#             */
/*   Updated: 2023/02/27 20:42:38 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
This function will render the first enemy xpm while moves are under 5
*/
void	render_en_r(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win, game->en_r.img1,
		pos.y, pos.x);
}

/*
This function will render the enemy idle animation, after resucitation render, 
and will loop until the end of the game
*/
void	render_en_i(t_game *game, t_point pos)
{
	if (game->res == 0)
		render_en_res(game, pos);
	else if (game->n_loops <= RATE)
		mlx_put_image_to_window(game->mlx, game->win, game->en_i.img1,
			pos.y, pos.x);
	else if (game->n_loops <= RATE * 2)
		mlx_put_image_to_window(game->mlx, game->win, game->en_i.img2,
			pos.y, pos.x);
	else if (game->n_loops <= RATE * 3)
		mlx_put_image_to_window(game->mlx, game->win, game->en_i.img3,
			pos.y, pos.x);
	else if (game->n_loops <= RATE * 4)
		mlx_put_image_to_window(game->mlx, game->win, game->en_i.img4,
			pos.y, pos.x);
	if (game->n_loops > RATE * 4)
	{
		game->n_loops = 0;
		render_en_i(game, pos);
	}
}

/*
This function will put to screen the enemy resuciation animation, 
and will do it only once after movement 5 of player
*/
void	render_en_res(t_game *game, t_point pos)
{
	if (game->n_loops <= RATE)
		mlx_put_image_to_window(game->mlx, game->win, game->en_r.img1,
			pos.y, pos.x);
	else if (game->n_loops <= RATE * 2)
		mlx_put_image_to_window(game->mlx, game->win, game->en_r.img2,
			pos.y, pos.x);
	else if (game->n_loops <= RATE * 3)
		mlx_put_image_to_window(game->mlx, game->win, game->en_r.img3,
			pos.y, pos.x);
	else if (game->n_loops <= RATE * 4)
		mlx_put_image_to_window(game->mlx, game->win, game->en_r.img4,
			pos.y, pos.x);
	if (game->n_loops >= RATE * 4)
		game->res = 1;
}

/*
This function will refresh enemies animations depending on their position
and player moves
*/
void	update_enemy(t_game	*game)
{
	t_en	*tmp;

	tmp = game->en;
	if (game->mov < 5)
	{		
		while (tmp)
		{
			render_en_r(game, tmp->pos);
			tmp = tmp->next;
		}
	}
	else if (game->mov > 5)
	{		
		while (tmp)
		{
			render_en_i(game, tmp->pos);
			tmp = tmp->next;
		}
	}
}

/*
This function will stock enemys position in a list to
allow animation in place
*/
void	stock_enemy(t_game *game, t_point crd)
{
	t_en	*en;
	t_en	*tmp;

	en = ft_calloc(1, sizeof(t_en));
	if (!en)
		ft_exit(game);
	en->pos = crd;
	if (!game->en)
		game->en = en;
	else
	{
		tmp = game->en;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = en;
	}
}
