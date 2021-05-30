/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:28:34 by rturnip           #+#    #+#             */
/*   Updated: 2021/02/09 01:11:22 by rturnip          ###   ########.fr       */
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

static void	put_zero_x(t_flags *flags)
{
	if (flags->type == 'p')
	{
		ft_putchar('0');
		ft_putchar('x');
	}
}

static int	put_string_plus(const char *s, int prec, int widt, t_flags *f)
{
	int i;
	int k;
	int z;

	k = 0;
	i = 0;
	if (!s)
		return (0);
	z = ' ';
	if (f->type == 'p' && s[0] == '0' && f->widt > ft_strlen(s) && f->prec > 0)
	{
		z = '0';
		put_zero_x(f);
		i = 1;
	}
	while (widt-- > 0)
		k += write(1, &z, 1);
	i != 1 ? put_zero_x(f) : i--;
	if (prec >= 0)
		while (s[i] && i < prec)
			ft_putchar(s[i++]);
	else
		while (s[i])
			ft_putchar(s[i++]);
	return (i + k);
}

static int	pointer_plus_minus(t_flags *flags, char *res)
{
	int i;
	int temp;

	i = 0;
	temp = flags->widt;
	if (flags->prec == 0 && res[0] == '0' && ft_strlen(res) == 1)
		res = ft_strdup("");
	if (flags->widt > ft_strlen(res))
		(*flags).widt -= (ft_strlen(res) + 2);
	else if (flags->widt < ft_strlen(res))
		(*flags).widt = 0;
	if ((*flags).minus == 1)
	{
		put_zero_x(flags);
		i = 2 + put_string_minus(res, (*flags).prec, (*flags).widt, flags);
	}
	else if ((*flags).minus == 0)
	{
		i = 2 + put_string_plus(res, (*flags).prec, (*flags).widt, flags);
	}
	return (i);
}

int			printf_pointer(t_flags *flags, unsigned long long arg)
{
	char	*res;
	int		i;

	i = 0;
	if (!arg)
		return (pointer_plus_minus(flags, "0"));
	letters_size((res = itoa_hex(arg)));
	i = pointer_plus_minus(flags, res);
	free(res);
	return (i);
}
