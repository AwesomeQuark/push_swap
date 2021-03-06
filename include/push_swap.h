/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:54:56 by conoel            #+#    #+#             */
/*   Updated: 2019/04/12 16:36:47 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <strings.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include "../haflib/includes/haflib.h"

# define SEC 1000000
# define MIN 25

typedef struct	s_elem
{
	char			root;
	int				nb;
	struct s_elem	*next;
	struct s_elem	*previous;
}				t_elem;

/*
** push_swap
*/
void			solve_list(t_elem *root_a, t_elem *root_b, int delay);
void			small_sort(t_elem *root_a, t_elem *root_b, int delay);
void			medium_sort(t_elem *root_a, t_elem *root_b, int delay);
void			long_sort(t_elem *root_a, t_elem *root_b, int delay);
void			very_long_sort(t_elem *root_a, t_elem *root_b, int delay);
/*
**	operations
*/
void			swap(t_elem *last_a);
void			double_swap(t_elem *last_a, t_elem *last_b);
void			rotate(t_elem *last);
void			double_rotate(t_elem *last_a, t_elem *last_b);
void			r_rotate(t_elem *last);
void			double_r_rotate(t_elem *last_a, t_elem *last_b);
void			push(t_elem *last_a, t_elem *last_b);

/*
**	specific functions
*/
t_elem			*load_a(int argc, char **argv);
void			print_stack(t_elem *root_a, t_elem *root_b, char *ft,
	t_elem *mark);
void			ft_free(t_elem *root_a, t_elem *root_b);
t_elem			*new(int nb, t_elem *next, t_elem *previous, char root);
int				issort(t_elem *root_a);
t_elem			*ft_get_min(t_elem *root_a);
t_elem			*ft_get_max(t_elem *root_a);
int				ft_get_index(t_elem *elem);
void			exec_ft(char *ft, t_elem *root_a, t_elem *root_b, int delay);
int				heap_size(t_elem *root);
int				get_pourcentage(t_elem *root, float pourcent);
void			cut_b(t_elem *root_a, t_elem *root_b, int mid_value, int delay);
void			cut_a(t_elem *root_a, t_elem *root_b, int mid_value, int delay);
void			solve_a(t_elem *root_a, t_elem *root_b, int max, int delay);
void			solve_b(t_elem *root_a, t_elem *root_b, int max, int delay);
int				ft_atoi_error(const char *nptr);

/*
** VISUAL
*/
void			print_rb(t_elem *b);
void			print_rrb(t_elem *b);
void			print_sa(t_elem *a, t_elem *mark);
void			print_sb(t_elem *b);
void			print_rra(t_elem *a, t_elem *mark);
void			print_ra(t_elem *a, t_elem *mark);
int				get_print_height(t_elem *a, t_elem *b);

#endif
