/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:12:04 by ancolmen          #+#    #+#             */
/*   Updated: 2023/02/27 16:59:27 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
This funtion will initialize the structures of the proposed tiles by the 
document map as well as the error structure. It will read and check, print 
errors if needed and return the map in a big tableau
*/
char	**check_map(t_game	*game)
{
	read_map(game);
	print_map_error(game);
	game->map.map = ft_split(game->map.big_line, '\n');
	if (!game->map.map)
		ft_exit(game);
	game->map.map_cpy = ft_split(game->map.big_line, '\n');
	if (!game->map.map_cpy)
		ft_exit(game);
	check_path(game);
	game->lay_cpy.collect = 0;
	return (game->map.map);
}

/*
This function will read the error and check line by line, 
updating the error and errors in the check function
*/
void	read_map(t_game	*game)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(game->map.fd);
		if (!line)
		{
			if (!game->lay.col)
				map_error("Map is empty or has only one column!\n", game);
			else
				check_errors(game->map.last_line, game, 1);
			break ;
		}
		free(game->map.last_line);
		check_errors(line, game, 0);
		game->map.last_line = ft_substr(line, 0, ft_strlen(line));
		game->map.big_line = concat_bg(game->map.big_line, line);
		if (!game->map.last_line || !game->map.big_line)
			ft_exit(game);
		free(line);
		game->lay.row++;
	}
}

/*
This function will check each line for errors
and update the error structure if needed
*/
void	check_errors(char *line, t_game *game, int last)
{
	game->map.len = ft_strlen(line);
	if (!game->lay.col)
	{
		game->lay.col = game->map.len - 1;
		if (ft_countchar(line, '1') != game->map.len - 1)
				game->lay.e_walls += 1;
	}
	if (game->lay.col && ((game->lay.col != game->map.len - 1
				&& ft_strchr(line, '\n')) || (game->lay.col != game->map.len
				&& !ft_strchr(line, '\n'))))
		game->lay.e_rowlen += 1;
	if ((line[0] != '1' || line[game->map.len - 2] != '1')
		|| (last && (ft_countchar(line, '1') != game->lay.col)))
		game->lay.e_walls += 1;
	game->lay.exit += ft_countchar(line, 'E');
	game->lay.player += ft_countchar(line, 'P');
	game->lay.enemy += ft_countchar(line, 'X');
	game->lay.collect += ft_countchar(line, 'C');
	game->lay.floor += ft_countchar(line, '0');
	while (line && *line)
	{
		if (!ft_strchr("01CPEX\n", *line))
			game->lay.e_c += 1;
		line++;
	}
}

/*
This function will change to 1 the contents of 
the error structure if needed
*/
void	print_map_error(t_game *game)
{
	if (game->lay.e_rowlen)
		map_error("Map is not rectangular!\n", game);
	if (game->lay.e_walls)
		map_error("Map is not surrounded by walls\n", game);
	if (game->lay.e_c)
		map_error("Unexpected character(s) in map!\n", game);
	if (game->lay.player != 1)
		map_error("You cannot play if there is not one player!\n", game);
	if (game->lay.collect < 1)
		map_error("There should be at least one collectible!\n", game);
	if (game->lay.exit != 1)
		map_error("Invalid number of exits!\n", game);
	if (game->lay.col > 30 || game->lay.row > 16)
		map_error("Invalid map size: 1920x1024 px or 30x16 lines max\n", game);
}

/*
This error function will free the map after check if necessary 
and will return a string whith the error message of your choice
*/
void	map_error(char	*str, t_game *game)
{
	ft_printf("Error\n%s\n", str);
	ft_exit(game);
}
