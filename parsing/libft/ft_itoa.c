/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:41:06 by adbaich           #+#    #+#             */
/*   Updated: 2021/11/18 11:08:24 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*n_is_neg(char *p, int n, int s)
{
	p[s] = '\0';
	if (n == -2147483648)
	{
		p[--s] = '8';
		n = n / 10;
	}
	p[0] = '-';
	while (s > 1)
	{
		s--;
		if (n < 0)
			n = n * -1;
		p[s] = (n % 10) + 48;
		n = n / 10;
	}
	return (p);
}

static char	*n_is_pos(char *p, int n, int s)
{
	p[s] = '\0';
	while (s >= 1)
	{
		s--;
		p[s] = (n % 10) + 48;
		n = n / 10;
	}
	return (p);
}

static int	somme(int k, int n)
{
	int	s;

	s = 1;
	if (n < 0)
	{
		k = n * -1;
		s++;
	}
	while ((k / 10) != 0)
	{
		k = k / 10;
		s++;
	}	
	return (s);
}

char	*ft_itoa(int n)
{
	int		i;
	int		k;
	int		s;
	char	*p;

	k = n;
	if (n == -2147483648)
	{
		s = 11;
		p = (char *)malloc(sizeof(char) * (s + 1));
		return (n_is_neg(p, n, s));
	}
	i = 0;
	s = somme(k, n);
	p = (char *)malloc(sizeof(char) * (s + 1));
	if (!p)
		return (NULL);
	if (n < 0)
		p = n_is_neg(p, n, s);
	else if (n >= 0)
		p = n_is_pos(p, n, s);
	return (p);
}
