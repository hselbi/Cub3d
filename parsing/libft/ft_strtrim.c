/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:43:35 by adbaich           #+#    #+#             */
/*   Updated: 2021/11/18 09:49:14 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	check(char const	s1, char const	*set)
{
	int	i;

	i = 0;
	while (*(set + i))
	{
		if (*(set + i) == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*moving(char	*p, size_t	is, size_t	il, const char	*s1)
{
	size_t	i;

	i = 0;
	while (*(s1 + is) && is <= il)
	{
		*(p + i) = *(s1 + is);
		i++;
		is++;
	}
	*(p + i) = '\0';
	return (p);
}	

char	*ft_strtrim(char const	*s1, char const	*set)
{
	size_t		len;
	size_t		il;
	size_t		is;
	char		*p;

	len = 0;
	if (!s1)
		return (NULL);
	while (check(s1[len], set))
		len++;
	is = len;
	len = ft_strlen(s1) - 1;
	while (check(s1[len], set) && len > 0)
		len--;
	il = len;
	if (is > il)
		len = 0;
	else
		len = il - is + 1;
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	return (moving(p, is, il, s1));
}
