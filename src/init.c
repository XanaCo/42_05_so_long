/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:53:48 by ancolmen          #+#    #+#             */
/*   Updated: 2023/02/28 13:06:56 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
This funtion will initialize the general structure of the game
*/
t_game	game_init(void)
{
	t_game	game;

	ft_bzero(&game, sizeof(game));
	return (game);
}

/*
This funtion will call all the loading functions
*/
void	load_all_xpm(t_game *game)
{
	map_init(game);
	event_init(game);
	digit_init(game);
	pl_r_init(game);
	pl_l_init(game);
	en_r_init(game);
	en_i_init(game);
}

/*
This funtion will load the xpm into the structure of the map
*/
void	map_init(t_game *game)
{
	game->fix.w_t = mlx_xpm_file_to_image(game->mlx, "img/w_t.xpm",
			&game->size.x, &game->size.y);
	game->fix.w_n = mlx_xpm_file_to_image(game->mlx, "img/w_ns1.xpm",
			&game->size.x, &game->size.y);
	game->fix.w_s = mlx_xpm_file_to_image(game->mlx, "img/w_ns2.xpm",
			&game->size.x, &game->size.y);
	game->fix.w_ew = mlx_xpm_file_to_image(game->mlx, "img/w_ew.xpm",
			&game->size.x, &game->size.y);
	game->fix.w_ne = mlx_xpm_file_to_image(game->mlx, "img/w_ne.xpm",
			&game->size.x, &game->size.y);
	game->fix.w_nw = mlx_xpm_file_to_image(game->mlx, "img/w_nw.xpm",
			&game->size.x, &game->size.y);
	game->fix.w_se = mlx_xpm_file_to_image(game->mlx, "img/w_se.xpm",
			&game->size.x, &game->size.y);
	game->fix.w_sw = mlx_xpm_file_to_image(game->mlx, "img/w_sw.xpm",
			&game->size.x, &game->size.y);
	game->fix.fl = mlx_xpm_file_to_image(game->mlx, "img/gr.xpm",
			&game->size.x, &game->size.y);
	game->fix.ex = mlx_xpm_file_to_image(game->mlx, "img/e_yw.xpm",
			&game->size.x, &game->size.y);
	game->fix.n_ex = mlx_xpm_file_to_image(game->mlx, "img/e_n.xpm",
			&game->size.x, &game->size.y);
	game->fix.col = mlx_xpm_file_to_image(game->mlx, "img/c_1.xpm",
			&game->size.x, &game->size.y);
}

/*
This funtion will load the xpm 'events' into the structure of the map
*/
void	event_init(t_game *game)
{
	game->fix.y_w = mlx_xpm_file_to_image(game->mlx, "img/sc_yw_1.xpm",
			&game->size.x, &game->size.y);
	game->fix.die = mlx_xpm_file_to_image(game->mlx, "img/die.xpm",
			&game->size.x, &game->size.y);
}

/*
This funtion will load the xpm digits into the number's array structure
*/
void	digit_init(t_game *game)
{
	game->dig = ft_calloc(10, sizeof(t_num));
	game->dig[0].img = mlx_xpm_file_to_image(game->mlx, "img/d_0.xpm",
			&game->size.x, &game->size.y);
	game->dig[1].img = mlx_xpm_file_to_image(game->mlx, "img/d_1.xpm",
			&game->size.x, &game->size.y);
	game->dig[2].img = mlx_xpm_file_to_image(game->mlx, "img/d_2.xpm",
			&game->size.x, &game->size.y);
	game->dig[3].img = mlx_xpm_file_to_image(game->mlx, "img/d_3.xpm",
			&game->size.x, &game->size.y);
	game->dig[4].img = mlx_xpm_file_to_image(game->mlx, "img/d_4.xpm",
			&game->size.x, &game->size.y);
	game->dig[5].img = mlx_xpm_file_to_image(game->mlx, "img/d_5.xpm",
			&game->size.x, &game->size.y);
	game->dig[6].img = mlx_xpm_file_to_image(game->mlx, "img/d_6.xpm",
			&game->size.x, &game->size.y);
	game->dig[7].img = mlx_xpm_file_to_image(game->mlx, "img/d_7.xpm",
			&game->size.x, &game->size.y);
	game->dig[8].img = mlx_xpm_file_to_image(game->mlx, "img/d_8.xpm",
			&game->size.x, &game->size.y);
	game->dig[9].img = mlx_xpm_file_to_image(game->mlx, "img/d_9.xpm",
			&game->size.x, &game->size.y);
}
