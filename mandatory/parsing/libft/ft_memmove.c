/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:46:54 by adbaich           #+#    #+#             */
/*   Updated: 2021/11/15 14:57:52 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = len - 1;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (i != -1)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
