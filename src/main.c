/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:09:28 by vthomas           #+#    #+#             */
/*   Updated: 2016/01/10 19:25:05 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "libft.h"
#include "tetri_gen.h"

int	main(int argc, char **argv)
{
	int i;
	int nb_tetri;

	srand(time(NULL));
	i = 0;
	if (argc != 2)
	{
		ft_putendl("Nombre d'argument incorrect'");
		return (-1);
	}
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_putendl("Argument invalide !");
			return (-1);
		}
		i++;
	}
	nb_tetri = ft_atoi(argv[1]);
	if (nb_tetri < 1 || nb_tetri > 26)
	{
		ft_putendl("Nombre invalide !");
		return (-1);
	}
	tetri_generate(nb_tetri);
	return (0);
}
