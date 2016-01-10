/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_tetri_validate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 16:30:53 by vthomas           #+#    #+#             */
/*   Updated: 2016/01/10 17:27:24 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "tetri_gen.h"

void	tetri_validate(unsigned short tetri)
{
	int value;

	value = 0;
	value += (tetri & 0x8000) ? 1:0;
	value += (tetri & 0x4000) ? 1:0;
	value += (tetri & 0x2000) ? 1:0;
	value += (tetri & 0x1000) ? 1:0;
	value += (tetri & 0x0800) ? 1:0;
	value += (tetri & 0x0400) ? 1:0;
	value += (tetri & 0x0200) ? 1:0;
	value += (tetri & 0x0100) ? 1:0;
	value += (tetri & 0x0080) ? 1:0;
	value += (tetri & 0x0040) ? 1:0;
	value += (tetri & 0x0020) ? 1:0;
	value += (tetri & 0x0010) ? 1:0;
	value += (tetri & 0x0008) ? 1:0;
	value += (tetri & 0x0004) ? 1:0;
	value += (tetri & 0x0002) ? 1:0;
	value += (tetri & 0x0001) ? 1:0;
	if (value != 4)
	{
		ft_putendl("error");
		exit(-1);
	}
}
