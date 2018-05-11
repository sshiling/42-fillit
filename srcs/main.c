/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:01:51 by sshiling          #+#    #+#             */
/*   Updated: 2017/11/13 15:01:56 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char			*ft_stars(char *str)
{
	int				i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i - 1] == '\n' && str[i] == '\n' && str[i + 1] == '\n')
			return (NULL);
		if (str[i - 1] == '\n' && str[i] == '\n' && str[i + 1] == '\0')
			return (NULL);
		if ((str[i] == '\0' || str[i] == '\n') && str[i - 1] == '\n')
			str[i] = '*';
		i++;
	}
	return (str);
}

static char			*ft_reader(char *path)
{
	char			*buf;
	int				fd;
	int				n;

	n = 545;
	if (!(buf = (char*)malloc(sizeof(char) * 547)))
		return (NULL);
	buf[547] = '\0';
	fd = open(path, O_RDONLY);
	if (fd == -1 || n < read(fd, buf, 546))
	{
		close(*path);
		return (NULL);
	}
	close(*path);
	return (&buf[0]);
}

static void			*ft_error(void)
{
	write(1, "error\n", 6);
	return (NULL);
}

static t_t			*ft_convert(char *path)
{
	char			*string;
	char			**str_array;
	t_t				*list;
	int				i;

	i = 0;
	string = ft_reader(path);
	if (!(string = ft_stars(string)))
		return (ft_error());
	str_array = ft_strsplit(string, '*');
	free(string);
	if (str_array == NULL || ft_checker(str_array) != 0)
		return (ft_error());
	i = 0;
	list = ft_struct_creator(str_array);
	while (str_array[i] != NULL)
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
	return (list);
}

int					main(int argc, char **argv)
{
	int				sq;
	int				count;
	t_t				*list;

	if (argc != 2)
		write(1, "usage: ./fillit source_file\n", 28);
	else
	{
		if (!(list = ft_convert(argv[1])))
			return (0);
		count = ft_count(list);
		if (count == 1)
		{
			ft_print(list);
			return (0);
		}
		sq = ft_square(count);
		ft_fillit(list, list, sq);
		ft_print(list);
		ft_delete_list(list);
	}
	return (0);
}
