/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:54:56 by conoel            #+#    #+#             */
/*   Updated: 2019/01/30 20:29:32 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <strings.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.a"

typedef struct		s_elem
{
	char			root;
	int				nb;
	struct s_elem	*next;
	struct s_elem	*previous;
}					t_elem;

typedef struct		s_ft
{
	char			ft[5];
	int				index;
	struct s_ft		*next;
}					t_ft;

//	operations
void		swap(t_elem *last_a);
void		double_swap(t_elem *last_a, t_elem *last_b);
void		rotate(t_elem **last);
void		double_rotate(t_elem **last_a, t_elem **last_b);
void		r_rotate(t_elem **last);
void		double_r_rotate(t_elem **last_a, t_elem **last_b);
void		push(t_elem *last_a, t_elem *last_b);

//	specific functions
t_elem		*load_a(int argc, char **argv);
void		print_stack(t_elem *root_a, t_elem *root_b);
void		ft_free(t_elem *root_a, t_elem *root_b);
t_elem		*new(int nb, t_elem *next, t_elem *previous, char root);
int			ft_get_index(t_elem *elem);
int			issort(t_elem *root_a);
t_elem		*ft_get_min(t_elem *root_a);
t_elem		*ft_get_max(t_elem *root_a);

//	general functions
int			ft_atoi(char *str);
int			ft_strcmp(char *s1, char *s2);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_bzero(char *s, size_t n);
char		**ft_strsplit(char const *s, char c);

#endif
