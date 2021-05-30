/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_uns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:25:34 by rturnip           #+#    #+#             */
/*   Updated: 2021/02/09 00:25:38 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

static unsigned int		ft_count(unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}

static void				ft_rev(char *itoa)
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

char					*printf_itoa_uns(unsigned int n)
{
	char			*itoa;
	int				i;
	unsigned int	count;
	long			g;

	g = n;
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	count = ft_count(n);
	if (!(itoa = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	itoa[count] = '\0';
	while (g > 0)
	{
		itoa[i++] = g % 10 + 48;
		g = g / 10;
	}
	ft_rev(itoa);
	return (itoa);
}

int						printf_uns(t_flags *flags, unsigned int a)
{
	char	*res;
	int		len;
	int		i;
	int		b;

	len = 0;
	i = 0;
	b = 0;
	res = printf_itoa_uns(a);
	if (flags->prec == 0 && res[0] == '0')
		res = ft_strdup("");
	if (flags->widt < flags->prec)
		(*flags).widt = flags->prec;
	if ((*flags).minus == 1 || (*flags).prec > -1)
		(*flags).zero = 0;
	if (flags->prec <= ft_strlen(res) && flags->widt <= ft_strlen(res))
		i = help_int_four(flags, res);
	else if ((*flags).prec > ft_strlen(res) && (*flags).widt <= (*flags).prec)
		i = help_int_four(flags, res);
	else if ((*flags).prec <= ft_strlen(res) && flags->widt > ft_strlen(res))
		i = printf_int_one_plus(flags, res);
	else if (flags->prec > ft_strlen(res) && flags->widt > flags->prec)
		i = printf_int_two_plus(flags, res);
	free(res);
	return (i);
}
