/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:29:05 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/03/09 15:31:42 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t items, size_t size)
{
	void	*buffer;

	if (items > sizeof(size_t) && size > sizeof(size_t))
		return (0);
	buffer = malloc(items * size);
	if (!buffer)
		return (0);
	else
		ft_bzero(buffer, items * size);
	return (buffer);
}
