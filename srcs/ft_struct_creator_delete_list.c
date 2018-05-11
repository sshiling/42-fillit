/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_creator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:23:44 by sshiling          #+#    #+#             */
/*   Updated: 2017/11/15 21:08:34 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void		ft_node_help(t_t *node, char *fig, int i)
{
	int		j;
	int		x;
	int		y;

	j = 0;
	x = 0;
	y = 0;
	while (fig[i] != '\0')
	{
		if (fig[i] == '\n')
		{
			y++;
			x = 0;
		}
		else if (fig[i] == '#')
		{
			(node->xs)[j] = x;
			(node->ys)[j] = y;
			j++;
			x++;
		}
		else
			x++;
		i++;
	}
}

static t_t			*ft_node(char *fig, int nb)
{
	t_t		*node;
	int		i;

	i = 0;
	node = malloc(sizeof(t_t));
	node->fill = 65 + nb;
	node->next = NULL;
	node->xs = malloc(16);
	node->ys = malloc(16);
	ft_node_help(node, fig, i);
	ft_simplify(node->xs);
	ft_simplify(node->ys);
	return (node);
}

t_t					*ft_struct_creator(char **array)
{
	t_t		*head;
	t_t		*cursor;
	t_t		*node;
	int		i;

	head = NULL;
	cursor = NULL;
	node = NULL;
	i = 0;
	while (array[i] != NULL)
	{
		node = ft_node(array[i], i);
		if (head == NULL)
		{
			head = node;
			cursor = head;
		}
		else
		{
			cursor->next = node;
			cursor = cursor->next;
		}
		i++;
	}
	return (head);
}

void				ft_delete_list(t_t *list)
{
	t_t			*cursor;
	t_t			*del;

	cursor = list;
	while (cursor != NULL)
	{
		del = cursor;
		cursor = cursor->next;
		free(del->xs);
		free(del->ys);
		free(del);
	}
	del = NULL;
}
