/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:00:20 by conoel            #+#    #+#             */
/*   Updated: 2019/04/12 16:51:36 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_char(int c, char maj)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'z' && !maj)
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'Z' && maj)
		return (c - 'A' + 10);
	return (0);
}

long long	ft_strtoll(char *ptr, size_t *index)
{
	long long	ret;
	int			sign;
	char		maj;
	size_t		i;

	ret = 0;
	maj = 0;
	i = 0;
	while (ft_isspace(ptr[i]))
		i++;
	sign = (ptr[i] == '-') ? -1 : 1;
	ptr[i] == '-' || ptr[i] == '+' ? i++ : 0;
	while (ft_isalphanum_base(ptr[i], base, maj))
	{
		ret *= 10;
		ret += ft_get_char(ptr[i++], maj);
	}
	(*index) += i;
	return (ret * sign);
}
