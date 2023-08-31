/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:53:48 by ancolmen          #+#    #+#             */
/*   Updated: 2023/02/27 18:55:36 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
This funtion will load the xpm of the idle right animation for the player
*/
void	pl_r_init(t_game *game)
{
	game->pl_r.img1 = mlx_xpm_file_to_image(game->mlx, "img/p_ir_1.xpm",
			&game->size.x, &game->size.y);
	game->pl_r.img2 = mlx_xpm_file_to_image(game->mlx, "img/p_ir_2.xpm",
			&game->size.x, &game->size.y);
	game->pl_r.img3 = mlx_xpm_file_to_image(game->mlx, "img/p_ir_3.xpm",
			&game->size.x, &game->size.y);
	game->pl_r.img4 = mlx_xpm_file_to_image(game->mlx, "img/p_ir_4.xpm",
			&game->size.x, &game->size.y);
}

/*
This funtion will load the xpm of the idle left animation for the player
*/
void	pl_l_init(t_game *game)
{
	game->pl_l.img1 = mlx_xpm_file_to_image(game->mlx, "img/p_il_1.xpm",
			&game->size.x, &game->size.y);
	game->pl_l.img2 = mlx_xpm_file_to_image(game->mlx, "img/p_il_2.xpm",
			&game->size.x, &game->size.y);
	game->pl_l.img3 = mlx_xpm_file_to_image(game->mlx, "img/p_il_3.xpm",
			&game->size.x, &game->size.y);
	game->pl_l.img4 = mlx_xpm_file_to_image(game->mlx, "img/p_il_4.xpm",
			&game->size.x, &game->size.y);
}

/*
This funtion will load the xpm of the 'resucitation' animation for the enemies
*/
void	en_r_init(t_game *game)
{
	game->en_r.img1 = mlx_xpm_file_to_image(game->mlx, "img/x_r_1.xpm",
			&game->size.x, &game->size.y);
	game->en_r.img2 = mlx_xpm_file_to_image(game->mlx, "img/x_r_2.xpm",
			&game->size.x, &game->size.y);
	game->en_r.img3 = mlx_xpm_file_to_image(game->mlx, "img/x_r_3.xpm",
			&game->size.x, &game->size.y);
	game->en_r.img4 = mlx_xpm_file_to_image(game->mlx, "img/x_r_4.xpm",
			&game->size.x, &game->size.y);
}

/*
This funtion will load the xpm of the idle animation for the enemies
*/
void	en_i_init(t_game *game)
{
	game->en_i.img1 = mlx_xpm_file_to_image(game->mlx, "img/x_i_1.xpm",
			&game->size.x, &game->size.y);
	game->en_i.img2 = mlx_xpm_file_to_image(game->mlx, "img/x_i_2.xpm",
			&game->size.x, &game->size.y);
	game->en_i.img3 = mlx_xpm_file_to_image(game->mlx, "img/x_i_3.xpm",
			&game->size.x, &game->size.y);
	game->en_i.img4 = mlx_xpm_file_to_image(game->mlx, "img/x_i_4.xpm",
			&game->size.x, &game->size.y);
}
