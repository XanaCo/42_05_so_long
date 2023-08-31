/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:49:32 by ancolmen          #+#    #+#             */
/*   Updated: 2023/02/20 16:24:38 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
This function will do a strjoin and free afterwards
*/
char	*concat_bg(char *big_line, char *str)
{
	char	*new_bg;

	new_bg = ft_strjoin(big_line, str);
	free(big_line);
	return (new_bg);
}
