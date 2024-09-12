/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:20:00 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/21 17:21:29 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	conv_manager(t_print *tab, const char *format, int i)
{
	if (format[i] == 'd' || format[i] == 'i')
		int_printer(va_arg(tab->args, int), tab);
	if (format[i] == 'c')
		char_printer(va_arg(tab->args, int), tab);
	if (format[i] == 's')
		str_printer(va_arg(tab->args, char *), tab);
	if (format[i] == 'p')
		ptr_printer(va_arg(tab->args, uintptr_t), tab);
	if (format[i] == 'u')
		uns_printer(va_arg(tab->args, unsigned int), tab);
	if (format[i] == 'x')
		hex_printer(va_arg(tab->args, unsigned int), tab, 0);
	if (format[i] == 'X')
		hex_printer(va_arg(tab->args, unsigned int), tab, 1);
	if (format[i] == '%')
		tab->tl += write(1, "%", 1);
	return (i);
}

static int	flag_manager_2(t_print *tab, const char *format, int i)
{
	if (format[i] == '+')
	{
		tab->plus = 1;
		i++;
	}
	if (format[i] == ' ')
	{
		tab->sp = 1;
		i++;
	}
	if (format[i] == '0')
	{
		if (tab->dash == 0 && tab->pnt == 0
			&& !(format[i - 1] >= '1' && format[i - 1] <= '9'))
			tab->zero = 1;
		i++;
	}
	if (format[i] >= '1' && format[i] <= '9')
	{
		if (tab->pnt == 1)
			tab->prc = ft_atoi(format + i);
		else
			tab->wdt = ft_atoi(format + i);
	}
	return (i);
}

int	flag_manager(t_print *tab, const char *format, int i)
{
	while (conv_check(format[i]) == 0)
	{
		if (format[i] == '.')
		{
			tab->pnt = 1;
			i++;
		}
		if (format[i] == '-')
		{
			tab->dash = 1;
			i++;
		}
		if (format[i] == '#')
		{
			tab->ash = 1;
			i++;
		}
		i = flag_manager_2(tab, format, i);
		while (format[i] >= '1' && format[i] <= '9')
			i++;
	}
	if (tab->dash || tab->pnt)
		tab->zero = 0;
	i = conv_manager (tab, format, i);
	return (i);
}
