/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:45:05 by rturnip           #+#    #+#             */
/*   Updated: 2021/02/08 18:45:32 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

int		help_int_four(t_flags *flags, char *res)
{
	int b;

	b = 0;
	if (flags->prec <= ft_strlen(res) && flags->widt <= ft_strlen(res))
	{
		(*flags).prec = ft_strlen(res);
		(*flags).widt = (*flags).prec;
		return (printf_string(flags, res));
	}
	else
	{
		b = (*flags).prec - ft_strlen(res);
		while ((*flags).prec-- > ft_strlen(res))
			ft_putchar('0');
		(*flags).widt = ft_strlen(res);
		(*flags).prec += 1;
		return (b + printf_string(flags, res));
	}
}

int		help_int_three(t_flags *flags, char *res)
{
	int b;

	b = 0;
	(*flags).widt--;
	b = (*flags).widt - ft_strlen(res) + 1;
	while ((*flags).widt-- > flags->prec)
		ft_putchar(' ');
	ft_putchar('-');
	(*flags).widt++;
	while ((*flags).widt-- > ft_strlen(res))
		ft_putchar('0');
	(*flags).widt = ft_strlen(res);
	return (b + printf_string(flags, res));
}

int		help_int_two(t_flags *flags, char *res)
{
	int b;

	b = 0;
	b = (*flags).widt - ft_strlen(res);
	(*flags).prec = (*flags).widt - 1;
	(*flags).widt--;
	while ((*flags).widt-- > ft_strlen(res))
		ft_putchar(' ');
	(*flags).widt = ft_strlen(res);
	ft_putchar('-');
	return (b + printf_string(flags, res));
}

int		help_int_one(t_flags *flags, char *res)
{
	int b;

	b = 0;
	b = (*flags).widt - ft_strlen(res);
	while ((*flags).widt-- > flags->prec)
		ft_putchar(' ');
	(*flags).widt++;
	while ((*flags).widt-- > ft_strlen(res))
		ft_putchar('0');
	(*flags).widt = ft_strlen(res);
	return (b + printf_string(flags, res));
}

int		printf_char(t_flags *flags, int c)
{
	int i;
	int k;

	i = 1;
	k = ' ';
	(*flags).widt--;
	if (flags->type == '%' && flags->zero == 1)
		k = '0';
	if ((*flags).minus == 1)
		ft_putchar(c);
	while ((*flags).widt > 0)
	{
		(*flags).widt--;
		ft_putchar(k);
		i++;
	}
	if ((*flags).minus == 0)
		ft_putchar(c);
	return (i);
}
