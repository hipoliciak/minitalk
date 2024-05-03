/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:17:58 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/03/09 14:03:56 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned int	i;
	char			*find;

	find = (char *)str;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)find[i] == (unsigned char)c)
			return ((void *)&find[i]);
		i++;
	}
	return (0);
}
