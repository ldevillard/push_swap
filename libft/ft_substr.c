/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:52:20 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/04 15:07:55 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_set_return(char *str)
{
	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	if (!s)
		return (NULL);
	if (start <= ft_strlen(s))
		str = malloc(sizeof(char) * len + 1);
	else
		return (ft_set_return(str));
	if (!str)
		return (NULL);
	while (i < start)
		i++;
	while (j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
