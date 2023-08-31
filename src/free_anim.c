/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:54:26 by ancolmen          #+#    #+#             */
/*   Updated: 2023/02/27 20:31:11 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
This function will destroy the player images
*/
void	free_player(t_game *game)
{
	if (game->pl_r.img1)
		mlx_destroy_image(game->mlx, game->pl_r.img1);
	if (game->pl_r.img2)
		mlx_destroy_image(game->mlx, game->pl_r.img2);
	if (game->pl_r.img3)
		mlx_destroy_image(game->mlx, game->pl_r.img3);
	if (game->pl_r.img4)
		mlx_destroy_image(game->mlx, game->pl_r.img4);
	if (game->pl_l.img1)
		mlx_destroy_image(game->mlx, game->pl_l.img1);
	if (game->pl_l.img2)
		mlx_destroy_image(game->mlx, game->pl_l.img2);
	if (game->pl_l.img3)
		mlx_destroy_image(game->mlx, game->pl_l.img3);
	if (game->pl_l.img4)
		mlx_destroy_image(game->mlx, game->pl_l.img4);
}

/*
This function will destroy the enemy images
*/
void	free_enemy(t_game *game)
{
	if (game->en_r.img1)
		mlx_destroy_image(game->mlx, game->en_r.img1);
	if (game->en_r.img2)
		mlx_destroy_image(game->mlx, game->en_r.img2);
	if (game->en_r.img3)
		mlx_destroy_image(game->mlx, game->en_r.img3);
	if (game->en_r.img4)
		mlx_destroy_image(game->mlx, game->en_r.img4);
	if (game->en_i.img1)
		mlx_destroy_image(game->mlx, game->en_i.img1);
	if (game->en_i.img2)
		mlx_destroy_image(game->mlx, game->en_i.img2);
	if (game->en_i.img3)
		mlx_destroy_image(game->mlx, game->en_i.img3);
	if (game->en_i.img4)
		mlx_destroy_image(game->mlx, game->en_i.img4);
}

/*
This function will free the enemy linked list positions
*/
void	free_list(t_en *enemy)
{
	t_en	*tmp;

	if (!enemy)
		return ;
	while (enemy)
	{
		tmp = enemy->next;
		free(enemy);
		enemy = tmp;
	}
}

/*
This function will detroy the collectibles images
*/
void	free_col(t_game *game)
{
	if (game->col.img1)
		mlx_destroy_image(game->mlx, game->col.img1);
	if (game->col.img2)
		mlx_destroy_image(game->mlx, game->col.img2);
	if (game->col.img3)
		mlx_destroy_image(game->mlx, game->col.img3);
	if (game->col.img4)
		mlx_destroy_image(game->mlx, game->col.img4);
}

/*
This function will detroy the digits images and free their pointer
*/
void	free_digits(t_game *game)
{
	if (game->dig[0].img)
		mlx_destroy_image(game->mlx, game->dig[0].img);
	if (game->dig[1].img)
		mlx_destroy_image(game->mlx, game->dig[1].img);
	if (game->dig[2].img)
		mlx_destroy_image(game->mlx, game->dig[2].img);
	if (game->dig[3].img)
		mlx_destroy_image(game->mlx, game->dig[3].img);
	if (game->dig[4].img)
		mlx_destroy_image(game->mlx, game->dig[4].img);
	if (game->dig[5].img)
		mlx_destroy_image(game->mlx, game->dig[5].img);
	if (game->dig[6].img)
		mlx_destroy_image(game->mlx, game->dig[6].img);
	if (game->dig[7].img)
		mlx_destroy_image(game->mlx, game->dig[7].img);
	if (game->dig[8].img)
		mlx_destroy_image(game->mlx, game->dig[8].img);
	if (game->dig[9].img)
		mlx_destroy_image(game->mlx, game->dig[9].img);
	if (game->dig)
		free(game->dig);
}
