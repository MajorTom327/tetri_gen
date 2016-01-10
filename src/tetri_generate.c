/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_generate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 17:27:37 by vthomas           #+#    #+#             */
/*   Updated: 2016/01/10 19:53:09 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "libft.h"
#include "tetri_gen.h"

static int check_down(int i, char *t)
{
	if (i < 14)
		if (t[i + 5] == '#')
		{
			t[i] = '#';
			return (1);
		}
	return (0);
}

static int check_up(int i, char *t)
{
	if (i > 4)
		if (t[i - 5] == '#')
		{
			t[i] = '#';
			return (1);
		}
	return (0);
}

static int check_left(int i, char *t)
{
	if (i != 0 && i != 5 && i != 10 && i != 15)
		if (t[i - 1] == '#')
		{
			t[i] = '#';
			return (1);
		}
	return (0);
}

static int check_right(int i, char *t)
{
	if (i != 3 && i != 8 && i != 13 && i != 18)
		if (t[i + 1] == '#')
		{
			t[i] = '#';
			return (1);
		}
	return (0);
}

static int check_pos(int i, char *t)
{
	if (t[i] != '#')
		return ((check_up(i, t) || check_left(i, t) || check_down(i, t) || check_right(i, t)));
	return (0);
}

static void doting(char *t)
{
	int i;

	t[4] = '\n';
	t[9] = '\n';
	t[14] = '\n';
	t[19] = '\n';
	t[20] = '\n';
	i = 0;
	while (i != 21)
	{
		if (t[i] != '\n')
			t[i] = '.';
		i++;
	}
}

int		tetri_generate(int nb)
{
	char	*tetri;
	int		positioned;
	int		cur_p;

	tetri = ft_strnew(21);
	if (nb == 0)
		return (0);
	positioned = 0;
	cur_p = 4;
	//TOURNER 4 FOIS POUR AVOIR UN TETRIMINOS
	doting(tetri);
	while (cur_p == 4 || cur_p == 9 || cur_p == 14 || cur_p >= 19 )
		cur_p = (rand() % BUF_SIZE);
	positioned++;
	tetri[cur_p] = '#';
	while (positioned != 4)
	{
		cur_p = (rand() % BUF_SIZE);
		while (cur_p == 4 || cur_p == 9 || cur_p == 14 || cur_p >= 19 )
			cur_p = (rand() % BUF_SIZE);
		if (check_pos(cur_p, tetri) == 1)
			positioned++;
	}
	ft_putstr(tetri);
	return (tetri_generate(nb - 1));
}
