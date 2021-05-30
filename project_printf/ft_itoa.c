/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:24:28 by rturnip           #+#    #+#             */
/*   Updated: 2021/02/09 00:24:50 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

static int		ft_count(int n)
{
	int	count;

	count = 0;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}

static void		ft_rev(char *itoa)
{
	int		i;
	int		len;
	char	one;

	i = 0;
	len = ft_strlen(itoa) - 1;
	while (i < len)
	{
		one = itoa[i];
		itoa[i] = itoa[len];
		itoa[len] = one;
		i++;
		len--;
	}
}

static int		ft_minus(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

void			help_fill_flags(t_flags *flags)
{
	if ((*flags).minus == 1 || (*flags).prec > -1)
		(*flags).zero = 0;
	if (flags->widt < flags->prec)
		(*flags).widt = flags->prec;
}

char			*ft_itoa(int n)
{
	char	*itoa;
	int		i;
	int		count;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	n = ft_minus(n);
	count = ft_count(n);
	if (!(itoa = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	itoa[count] = '\0';
	while (n > 0)
	{
		itoa[i++] = n % 10 + 48;
		n = n / 10;
	}
	ft_rev(itoa);
	return (itoa);
}
