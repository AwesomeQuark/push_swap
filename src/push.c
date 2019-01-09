/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:57:07 by conoel            #+#    #+#             */
/*   Updated: 2019/01/09 13:11:37 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_elem *root1, t_elem *root2)
{
	if (root1->next == root1)
		return ;
	t_elem	*last1;
	t_elem	*last2;
	t_elem	*moving;

	last1 = root1->previous->previous;
	last2 = root2->previous;
	moving = root1->previous;

	moving->next = root2;
	moving->previous = last2;
	root1->previous = last1;
	last1->next = root1;
	root2->previous = moving;
	last2->next = moving;
}