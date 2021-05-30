/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf_parse_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:38:49 by rturnip           #+#    #+#             */
/*   Updated: 2021/02/08 20:38:58 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void		ft_make_flag(t_flags *flag)
{
	(*flag).minus = 0;
	(*flag).zero = 0;
	(*flag).prec = -1;
	(*flag).star = 0;
	(*flag).widt = 0;
	(*flag).type = 0;
}

void		check_minus_null(t_flags *flags, char c)
{
	if (c == '-')
		(*flags).minus = 1;
	else
		(*flags).zero = 1;
}

int			fill_width(va_list list, t_flags *flags, const char *line, int i)
{
	if (line[i] == '*')
	{
		(*flags).widt = va_arg(list, int);
		i++;
	}
	else
	{
		(*flags).widt = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]))
			i++;
	}
	if ((*flags).widt < 0)
	{
		(*flags).minus = 1;
		(*flags).widt = (*flags).widt * -1;
	}
	return (i);
}

int			fill_prec(va_list list, t_flags *flags, const char *line, int i)
{
	i++;
	if ((line[i] != '*') && (!ft_isdigit(line[i])))
	{
		(*flags).prec = 0;
		return (i);
	}
	if (line[i] == '*')
	{
		(*flags).prec = va_arg(list, int);
		i++;
	}
	else
	{
		(*flags).prec = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]))
			i++;
	}
	return (i);
}

int			parse_flag(t_flags *flag, const char *line, va_list list, int i)
{
	ft_make_flag(flag);
	i++;
	while ((*flag).type == 0)
	{
		if (!(ft_str_check("012345678.9-*cspdiuxX%", line[i])))
			return (0);
		if (line[i] == '0' || line[i] == '-')
		{
			check_minus_null(flag, line[i]);
			i++;
		}
		if ((ft_str_check("0123456789*", line[i])))
			i = fill_width(list, flag, line, i);
		if (line[i] == '.')
			i = fill_prec(list, flag, line, i);
		if (ft_str_check("cspdiuxX%", line[i]))
			(*flag).type = line[i];
	}
	return (i);
}
