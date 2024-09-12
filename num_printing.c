/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_printing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:36:57 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/21 17:37:59 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	sign_printer(t_print *tab)
{
	if (tab->sign >= 0 && tab->plus)
		tab->tl += write(1, "+", 1);
	if (tab->sign < 0)
		tab->tl += write(1, "-", 1);
	if (tab->sp && !tab->plus && tab->sign >= 0)
		tab->tl += write(1, " ", 1);
}

void	ash_printer(t_print *tab, int c)
{
	if (tab->ash)
	{
		if (c)
			tab->tl += write(1, "0X", 2);
		else
			tab->tl += write(1, "0x", 2);
	}
}

void	int_printer(int n, t_print *tab)
{
	char	*s;

	s = ft_special_itoa(n, tab);
	if (tab->pnt && !tab->prc && n == 0)
		tab->is_zero = 1;
	if (ft_sstrlen(s) > tab->prc)
		tab->prc = ft_sstrlen(s);
	if (tab->zero)
		z_int_printer(tab, s);
	else
	{
		if (tab->is_zero)
			tab->prc = 0;
		num_wdt_manager(tab, s);
		if (!tab->is_zero)
			ft_putstr_fd(s, 1);
		num_wdt_manager(tab, s);
		if (!tab->is_zero)
			tab->tl += ft_sstrlen(s);
	}
	free (s);
	return ;
}

void	uns_printer(unsigned int n, t_print *tab)
{
	char	*s;

	s = ft_unsigned_itoa(n);
	if (tab->pnt && !tab->prc && n == 0)
		tab->is_zero = 1;
	if (ft_sstrlen(s) > tab->prc)
		tab->prc = ft_sstrlen(s);
	if (tab->zero)
		z_uns_printer(tab, s);
	else
	{
		if (tab->is_zero)
			tab->prc = 0;
		num_wdt_manager(tab, s);
		if (!tab->is_zero)
			ft_putstr_fd(s, 1);
		num_wdt_manager(tab, s);
		if (!tab->is_zero)
			tab->tl += ft_sstrlen(s);
	}
	free (s);
	return ;
}

void	hex_printer(unsigned int n, t_print *tab, int c)
{
	char	*s;

	if (c)
		s = ft_itoa_base("0123456789ABCDEF", n);
	else
		s = ft_itoa_base("0123456789abcdef", n);
	if (tab->pnt && !tab->prc && n == 0)
		tab->is_zero = 1;
	if (ft_sstrlen(s) > tab->prc)
		tab->prc = ft_sstrlen(s);
	if (tab->zero)
		z_hex_printer(tab, s, c);
	else
		w_hex_printer(tab, s, c, n);
	free (s);
	return ;
}
