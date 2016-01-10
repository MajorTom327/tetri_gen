/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 11:54:22 by vthomas           #+#    #+#             */
/*   Updated: 2016/01/10 17:25:06 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "tetri_gen.h"

static int				verif_tetri(char *str)
{
	size_t index;

	index = 0;
	if (strlen(str) != 21)
		return (-1);
	while (index++ != ft_strlen(str))
	{
		if ((index <= 3) || (index >= 5 && index <= 8) ||
			(index >= 10 && index <= 13) || (index >= 15 && index <= 18))
		{
			if (str[index] == '.' || str[index] == '#')
				continue;
			return ((int)index);
		}
		if (str[index] == '\n')
			continue;
		else
			return ((int)index);
	}
	return (-1);
}

unsigned short			*tetri_read(char *path)
{
	char			*buf;
	unsigned short	*val;

	val = 0;
	buf = (char *)malloc(sizeof(char) * 21);
	while (ft_strcpy(path, buf))
	{
		buf[21] = '\0';
		if (verif_tetri(buf) == -1)
		{
			return (0);
		}
	}
	ft_strdel(&buf);
	return (val);
}
