/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:35:18 by adbaich           #+#    #+#             */
/*   Updated: 2021/11/17 10:57:56 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*p;
	char	*m;

	if (!dst && !src)
		return (NULL);
	i = 0;
	p = (char *)dst;
	m = (char *)src;
	while (i < n)
	{
		p[i] = m[i];
		i++;
	}
	return (dst);
}
