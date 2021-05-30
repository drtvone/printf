/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:05:57 by rturnip           #+#    #+#             */
/*   Updated: 2021/02/09 00:25:54 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

int				ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str && i < 2147483647 && str[i] != '\0')
		i++;
	return (i);
}

int				ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

char			*ft_strdup(const char *s1)
{
	int		size;
	int		i;
	char	*s2;

	size = ft_strlen(s1) + 1;
	i = 0;
	if (!(s2 = (char *)malloc(size * sizeof(char))))
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static int		ft_space(const char *str)
{
	int i;

	i = 0;
	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\n') ||
			(str[i] == '\r') || (str[i] == '\t') || (str[i] == '\v'))
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	int i;
	int c;
	int k;

	k = 0;
	c = 1;
	if (!str)
		return (0);
	i = ft_space(str);
	if (str[i] == 45)
	{
		c = -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while (str[i] && str[i] > 47 && str[i] < 58)
	{
		k = (str[i] - 48) + k * 10;
		i++;
	}
	return (k * c);
}
