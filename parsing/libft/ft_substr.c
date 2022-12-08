/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:43:19 by adbaich           #+#    #+#             */
/*   Updated: 2021/11/18 09:24:51 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || (start == 0 && len == 0))
		return (ft_strdup(""));
	if (ft_strlen(s) < len && start == 0)
		return (ft_strdup(s));
	if (ft_strlen(s) < len)
		p = malloc(sizeof(char) * (len - start) + 1);
	else
		p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (s[start] && i < len)
	{
		p[i] = s[start];
		start++;
		i++;
	}
	*(p + i) = '\0';
	return (p);
}
