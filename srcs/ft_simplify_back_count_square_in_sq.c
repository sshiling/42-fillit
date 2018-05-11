/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 18:51:02 by noprysk           #+#    #+#             */
/*   Updated: 2017/11/18 18:51:04 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_simplify(int *array)
{
	int		i;
	int		min;

	i = 0;
	min = 1000;
	while (i < 4)
	{
		if (array[i] < min)
			min = array[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		array[i] -= min;
		i++;
	}
}

void		ft_back(t_t *list)
{
	t_t		*cursor;

	cursor = list;
	while (cursor != NULL)
	{
		ft_simplify(cursor->xs);
		ft_simplify(cursor->ys);
		cursor = cursor->next;
	}
}

int			ft_count(t_t *alst)
{
	int		n;
	t_t		*list;

	if (!(alst))
		return (0);
	n = 0;
	list = alst;
	while (list)
	{
		list = list->next;
		n++;
	}
	return (n);
}

int			ft_square(int x)
{
	int n;

	n = 0;
	while (n * n < x * 4)
		n++;
	return (n - 1);
}

int			ft_in_sq(int *array, int sq)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (array[i] > sq)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
