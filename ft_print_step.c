/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:02:22 by noprysk           #+#    #+#             */
/*   Updated: 2017/11/17 14:02:25 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

static int		ft_max(t_t *list)
{
	int		nb;
	int		j;
	t_t		*cursor;

	nb = 0;
	cursor = list;
	while (cursor != NULL)
	{
		j = 0;
		while (j <= 3)
		{
			if ((cursor->ys)[j] > nb)
				nb = (cursor->ys)[j];
			if ((cursor->xs)[j] > nb)
				nb = (cursor->xs)[j];
			j++;
		}
		cursor = cursor->next;
	}
	return (nb);
}

static char		ft_search(t_t *list, int x, int y)
{
	t_t		*cursor;
	int		j;

	cursor = list;
	while (cursor != NULL)
	{
		j = 0;
		while (j <= 3)
		{
			if ((cursor->xs)[j] == x && (cursor->ys)[j] == y)
				return (cursor->fill);
			j++;
		}
		cursor = cursor->next;
	}
	return ('!');
}

static void		ft_print_row(t_t *list, int y, int max)
{
	int		x;
	char	ch;

	x = 0;
	while (x <= max)
	{
		ch = ft_search(list, x, y);
		if (ch != '!')
			ft_putchar(ch);
		else
			ft_putchar('.');
		x++;
	}
	ft_putchar('\n');
}

void			ft_print(t_t *list)
{
	int		max;
	int		y;

	max = ft_max(list);
	y = 0;
	while (y <= max)
	{
		ft_print_row(list, y, max);
		y++;
	}
}

t_t				*ft_step(t_t *list, t_t *node)
{
	t_t *back;

	back = list;
	if (node == list)
		return (NULL);
	while (back->next != node)
		back = back->next;
	return (back);
}
