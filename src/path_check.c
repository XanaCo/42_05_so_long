/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:16:41 by ancolmen          #+#    #+#             */
/*   Updated: 2023/02/27 16:59:53 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
This function parses the map point by point and calls 
flood if it is possible, changing the map_cpy.
*/
void	check_path(t_game *game)
{
	t_point	crd;

	crd.y = 0;
	while (crd.y < (int)game->lay.col)
	{
		crd.x = 0;
		while (crd.x < (int)game->lay.row)
		{
			if (game->map.map_cpy[crd.x][crd.y] == 'P')
			{
				game->plpos.x = crd.x;
				game->plpos.y = crd.y;
				check_tiles(crd.x, crd.y, game);
			}
			crd.x++;
		}
		crd.y++;
	}
	if (game->lay.exit != game->lay_cpy.exit)
		map_error("There is something wrong with your game path!\n", game);
	if (game->lay.collect != game->lay_cpy.collect)
		map_error("All collectibles must be accesible!\n", game);
	return ;
}

/*
This function checks tiles NSEW and calls itelf in recursive if needed
*/
void	check_tiles(int x, int y, t_game *game)
{
	if (game->map.map_cpy[x][y] == '1')
		return ;
	if (game->map.map_cpy[x][y] == 'W')
		return ;
	if (game->map.map_cpy[x][y] == 'E')
		game->lay_cpy.exit++;
	if (game->map.map_cpy[x][y] == 'C')
		game->lay_cpy.collect++;
	game->map.map_cpy[x][y] = 'W';
	check_tiles(x + 1, y, game);
	check_tiles(x - 1, y, game);
	check_tiles(x, y + 1, game);
	check_tiles(x, y - 1, game);
	return ;
}
