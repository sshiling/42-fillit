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

#include "./libft/libft.h"
#include "fillit.h"

static int		ft_overlap(int *first_xs, int *first_ys,
									int *second_xs, int *second_ys)
{
	int			i;
	int			j;

	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (first_xs[i] == second_xs[j] && first_ys[i] == second_ys[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void		ft_add(int *array, int value)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		array[i] += value;
		i++;
	}
}

static int		ft_no_overlap(t_t *list, t_t *node)
{
	t_t			*cursor;

	cursor = list;
	while (cursor != node)
	{
		if (ft_overlap(cursor->xs, cursor->ys, node->xs, node->ys) == 1)
			return (1);
		cursor = cursor->next;
	}
	return (0);
}

static void		ft_help(t_t *list, t_t **node, int *sq)
{
	if (*node == list)
	{
		ft_back(list);
		(*sq)++;
	}
	else
	{
		ft_simplify((*node)->xs);
		ft_simplify((*node)->ys);
		*node = ft_step(list, *node);
		if (ft_similar(*node, (*node)->next) == 0)
		{
			ft_help(list, node, sq);
			return ;
		}
		ft_add((*node)->xs, 1);
	}
}

void			ft_fillit(t_t *list, t_t *node, int sq)
{
	while (1 == 1)
	{
		if (ft_no_overlap(list, node) == 0 && ft_in_sq(node->xs, sq) == 0
												&& ft_in_sq(node->ys, sq) == 0)
		{
			if (node->next == NULL)
				break ;
			node = node->next;
		}
		else if (ft_no_overlap(list, node) == 1 && ft_in_sq(node->xs, sq) == 0
												&& ft_in_sq(node->ys, sq) == 0)
			ft_add(node->xs, 1);
		else if (ft_in_sq(node->xs, sq) == 1 && ft_in_sq(node->ys, sq) == 0)
		{
			ft_simplify(node->xs);
			ft_add(node->ys, 1);
		}
		else
			ft_help(list, &node, &sq);
	}
}
