/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:58:23 by conoel            #+#    #+#             */
/*   Updated: 2019/02/11 17:28:49 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	solve_a(t_elem *root_a, t_elem *root_b, int max, int delay)
{
	int		size;
	int		index;
	t_elem	*tmp;

	size = ft_get_index((root_a)->next);
	while (root_a->next != root_a && max--)
	{
		tmp = ft_get_max(root_a);
		index = ft_get_index(tmp);
		if (index > size / 2)
			while ((root_a)->previous != tmp)
				exec_ft("rra", root_a, root_b, delay);
		else
			while ((root_a)->previous != tmp)
				exec_ft("ra", root_a, root_b, delay);
		exec_ft("pa", root_a, root_b, delay);
		size--;
	}
}

static void	solve_b(t_elem *root_a, t_elem *root_b, int max, int delay)
{
	int		size;
	int		index;
	t_elem	*tmp;

	size = ft_get_index((root_b)->next);
	while (root_b->next != root_b && max--)
	{
		tmp = ft_get_min(root_b);
		index = ft_get_index(tmp);
		if (index > size / 2)
			while ((root_b)->previous != tmp)
				exec_ft("rrb", root_a, root_b, delay);
		else
			while ((root_b)->previous != tmp)
				exec_ft("rb", root_a, root_b, delay);
		exec_ft("pb", root_a, root_b, delay);
		size--;
	}
}

void		solve_list(t_elem *root_a, t_elem *root_b, int delay)
{
	while (root_a->next != root_a && !issort(root_a))
	{
		cut_a(root_a, root_b, get_median(root_a), delay);
		if (heap_size(root_a) <= MIN)
			solve_a(root_a, root_b, heap_size(root_a), delay);
	}
	while (heap_size(root_b) >= MIN * 2)
	{
		solve_b(root_a, root_b, MIN * 3, delay);
		while (heap_size(root_b) > 0)
			cut_b(root_a, root_b, get_median(root_b), delay);
		while (!issort(root_a))
			exec_ft("pa", root_a, root_b, delay);
		exec_ft("pa", root_a, root_b, delay);
	}
	solve_b(root_a, root_b, heap_size(root_b), delay);
}

int			main(int argc, char **argv)
{
	t_elem	*root_a;
	t_elem	*root_b;
	int		delay;

	argc == 1 ? exit_(NULL) : 0;
	root_a = load_a(argc, argv);
	if (!(root_b = new(0, NULL, NULL, 1)))
	{
		ft_free(root_a, root_b);
		exit_(NULL);
	}
	root_b->next = root_b;
	root_b->previous = root_b;
	if (argc > 2 && argv[argc - 1][0] == 'c')
		delay = ft_atoi(&(argv[argc - 1][1]));
	else
		delay = -1;
	if (root_a == NULL)
		exit_(NULL);
	else if (heap_size(root_a) <= 3)
		small_sort(root_a, root_b, delay);
	else if (heap_size(root_a) <= 20)
		medium_sort(root_a, root_b, delay);
	solve_list(root_a, root_b, delay);
	ft_free(root_a, root_b);
}