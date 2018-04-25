/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:25:42 by sshiling          #+#    #+#             */
/*   Updated: 2017/12/06 13:25:44 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <ctype.h>
# include <fcntl.h>

typedef struct		s_tetri
{
	int				*xs;
	int				*ys;
	char			fill;
	struct s_tetri	*next;
}					t_t;

t_t					*ft_struct_creator(char **array);
int					ft_checker(char **str_array);
void				ft_simplify(int *array);
void				ft_back(t_t *list);
int					ft_count(t_t *alst);
void				ft_print(t_t *list);
int					ft_square(int x);
void				ft_fillit(t_t *list, t_t *node, int sq);
int					ft_in_sq(int *array, int sq);
t_t					*ft_step(t_t *list, t_t *node);
void				ft_delete_list(t_t *list);
int					ft_similar(t_t *node, t_t *next);

#endif
