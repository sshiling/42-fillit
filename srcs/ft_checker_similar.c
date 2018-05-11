/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 20:50:44 by sshiling          #+#    #+#             */
/*   Updated: 2017/11/15 21:07:56 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_not_tetrim(char *str)
{
	int			i;
	int			k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			k = (k == 0) ? 1 : k;
			if (i < 15 && str[i + 1] == '#'
				&& str[i + 5] == '#' && str[i + 6] == '#')
				return (0);
			if (str[i + 1] == '#')
				k++;
			if (str[i + 5] == '#' && i < 15)
				k++;
		}
		i++;
	}
	return ((k != 4) ? 1 : 0);
}

static int		ft_check_elements(char *str)
{
	int			i;
	int			x;
	int			y;
	int			z;

	i = 0;
	x = 0;
	y = 0;
	z = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (1);
		if (str[i] == '\n' && (i - x) % 4 == 0)
			x++;
		if (str[i] == '.')
			y++;
		if (str[i] == '#')
			z++;
		i++;
	}
	if (x != 4 || y != 12 || z != 4 || i != 20)
		return (1);
	return (0);
}

static int		ft_min(int *array)
{
	int			i;
	int			min;

	i = 0;
	min = 99;
	while (i < 4)
	{
		if (array[i] < min)
			min = array[i];
		i++;
	}
	return (min);
}

int				ft_similar(t_t *node, t_t *next)
{
	int			i;
	int			min;

	i = 0;
	min = ft_min(node->xs);
	while (i < 4)
	{
		if (node->xs[i] - min != next->xs[i])
			return (1);
		i++;
	}
	i = 0;
	min = ft_min(node->ys);
	while (i < 4)
	{
		if (node->ys[i] - min != next->ys[i])
			return (1);
		i++;
	}
	return (0);
}

int				ft_checker(char **str_array)
{
	int			i;

	i = 0;
	if (str_array == NULL)
		return (1);
	while (str_array[i] != '\0')
	{
		if (ft_check_elements(str_array[i]) != 0)
			return (2);
		i++;
	}
	if (i < 1 || i > 26)
		return (3);
	i = 0;
	while (str_array[i] != '\0')
	{
		if (ft_not_tetrim(str_array[i]) != 0)
			return (4);
		i++;
	}
	return (0);
}
