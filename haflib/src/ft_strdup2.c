/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:45:43 by conoel            #+#    #+#             */
/*   Updated: 2019/04/12 16:39:02 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup2(const char *s)
{
	int		index;
	char	*end;

	index = ft_strlen2(s) + 1;
	if (!(end = (char *)malloc(sizeof(char) * (index))))
		return (0);
	while (--index >= 0)
		end[index] = s[index];
	return (end);
}
