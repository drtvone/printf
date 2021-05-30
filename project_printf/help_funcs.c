/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:39:30 by rturnip           #+#    #+#             */
/*   Updated: 2021/02/09 00:40:16 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	help_funcs(t_flags *flag)
{
	if ((*flag).minus == 1 || (*flag).prec > -1)
		(*flag).zero = 0;
	if (flag->widt < flag->prec)
		(*flag).widt = flag->prec;
}

int		help_funcs_two(t_flags *flags, char *res)
{
	(*flags).prec = ft_strlen(res);
	(*flags).widt = (*flags).prec;
	ft_putchar('-');
	return (1 + printf_string(flags, res));
}
