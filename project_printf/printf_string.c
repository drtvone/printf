/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:06:38 by rturnip           #+#    #+#             */
/*   Updated: 2021/02/08 20:07:37 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

static int	put_string_minus(const char *s, int prec, int widt, t_flags *flags)
{
	int i;
	int z;

	i = 0;
	if (!s)
		return (0);
	if (prec >= 0)
		while (s[i] && i < prec)
			ft_putchar(s[i++]);
	else
		while (s[i])
			ft_putchar(s[i++]);
	z = ' ';
	if (flags->type == 's' && flags->zero == 1 && flags->minus == 0)
		z = '0';
	while (widt-- > 0)
	{
		ft_putchar(z);
		i++;
	}
	return (i);
}

static int	put_string_plus(const char *s, int prec, int widt, t_flags *flags)
{
	int i;
	int k;
	int z;

	k = 0;
	i = 0;
	if (!s)
		return (0);
	z = ' ';
	if (flags->type == 's' && flags->zero == 1 && flags->minus == 0)
		z = '0';
	while (widt-- > 0)
		k += write(1, &z, 1);
	if (prec >= 0)
		while (s[i] && i < prec)
			ft_putchar(s[i++]);
	else
		while (s[i])
			ft_putchar(s[i++]);
	return (i + k);
}

int			printf_string(t_flags *flags, const char *arg)
{
	int i;
	int len;

	i = 0;
	if (!arg)
		arg = "(null)";
	len = ft_strlen(arg);
	if (len > (*flags).prec && (*flags).prec >= 0)
		(*flags).widt = (*flags).widt - (*flags).prec;
	else
		(*flags).widt = (*flags).widt - len;
	if ((*flags).minus == 1)
		i = put_string_minus(arg, (*flags).prec, (*flags).widt, flags);
	if ((*flags).minus == 0)
		i = put_string_plus(arg, (*flags).prec, (*flags).widt, flags);
	return (i);
}
