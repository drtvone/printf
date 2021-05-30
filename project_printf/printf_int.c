/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:06:11 by rturnip           #+#    #+#             */
/*   Updated: 2021/02/09 00:40:51 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

int			printf_int_one_plus(t_flags *flags, char *res)
{
	int b;

	b = 0;
	b = (*flags).widt - ft_strlen(res);
	if (flags->zero == 1)
	{
		(*flags).prec = (*flags).widt;
		while ((*flags).widt-- > ft_strlen(res))
			ft_putchar('0');
		return (b + printf_string(flags, res));
	}
	else if (flags->minus == 0)
	{
		(*flags).prec = (*flags).widt;
		while ((*flags).widt-- > ft_strlen(res))
			ft_putchar(' ');
		(*flags).widt = ft_strlen(res);
		return (b + printf_string(flags, res));
	}
	else
	{
		(*flags).prec = (*flags).widt;
		return (printf_string(flags, res));
	}
}

int			printf_int_two_plus(t_flags *flags, char *res)
{
	int b;

	b = 0;
	if (flags->zero == 1)
	{
		while ((*flags).widt-- > ft_strlen(res))
			ft_putchar('0');
		return (b + printf_string(flags, res));
	}
	else if (flags->minus == 0)
		return (help_int_one(flags, res));
	else
	{
		b = (*flags).prec - ft_strlen(res);
		while ((*flags).prec-- > (ft_strlen(res)))
			ft_putchar('0');
		(*flags).widt -= b;
		(*flags).prec++;
		return (b + printf_string(flags, res));
	}
}

int			printf_int_one(t_flags *flags, char *res)
{
	int	b;

	b = 0;
	b = (*flags).widt - ft_strlen(res);
	if (flags->zero == 1)
	{
		(*flags).prec = (*flags).widt - 1;
		(*flags).widt--;
		ft_putchar('-');
		while ((*flags).widt-- > ft_strlen(res))
			ft_putchar('0');
		return (b + printf_string(flags, res));
	}
	else if (flags->minus == 0)
		return (help_int_two(flags, res));
	else
	{
		(*flags).prec = (*flags).widt - 1;
		(*flags).widt--;
		ft_putchar('-');
		return (1 + printf_string(flags, res));
	}
}

int			printf_int_two(t_flags *flags, char *res)
{
	int b;

	b = 0;
	if (flags->zero == 1)
	{
		ft_putchar('-');
		while ((*flags).widt-- > ft_strlen(res))
			ft_putchar('0');
		return (b + printf_string(flags, res));
	}
	else if (flags->minus == 0)
		return (help_int_three(flags, res));
	else
	{
		(*flags).widt--;
		b = (*flags).prec - ft_strlen(res);
		ft_putchar('-');
		while ((*flags).prec-- > (ft_strlen(res)))
			ft_putchar('0');
		(*flags).widt -= b;
		(*flags).prec++;
		return (b + 1 + printf_string(flags, res));
	}
}

int			printf_int(t_flags *flag, int a)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	if (a >= 0)
	{
		help_funcs(flag);
		res = ft_itoa(a);
		if (flag->prec == 0 && res[0] == '0')
			res = ft_strdup("");
		if (flag->prec <= ft_strlen(res) && flag->widt <= ft_strlen(res))
			i = help_int_four(flag, res);
		else if ((*flag).prec > ft_strlen(res) && (*flag).widt <= (*flag).prec)
			i = help_int_four(flag, res);
		else if ((*flag).prec <= ft_strlen(res) && flag->widt > ft_strlen(res))
			i = printf_int_one_plus(flag, res);
		else if (flag->prec > ft_strlen(res) && flag->widt > flag->prec)
			i = printf_int_two_plus(flag, res);
	}
	else if (a >= -2147483648)
		i = help_int_five_minus(flag, 0, res, a);
	free(res);
	return (i);
}
