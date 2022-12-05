/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:46:29 by adbaich           #+#    #+#             */
/*   Updated: 2021/11/15 14:10:25 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*m;
	size_t			i;

	i = 0;
	p = (unsigned char *)s1;
	m = (unsigned char *)s2;
	while (i < n)
	{
		if (p[i] != m[i])
			return (p[i] - m[i]);
		i++;
	}
	return (0);
}
