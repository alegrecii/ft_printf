/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_flag_printers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:41:28 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/21 17:42:01 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	z_int_printer(t_print *tab, char *s)
{
	if ((tab->sign >= 0 && tab->plus) || (tab->sign < 0) || tab->sp)
		tab->wdt--;
	sign_printer(tab);
	zero_printer((tab->wdt - tab->prc), tab);
	ft_putstr_fd(s, 1);
	tab->tl += tab->prc;
}

void	z_uns_printer(t_print *tab, char *s)
{
	if ((tab->sign >= 0 && tab->plus) || (tab->sign < 0) || tab->sp)
		tab->wdt--;
	sign_printer(tab);
	zero_printer((tab->wdt - tab->prc), tab);
	ft_putstr_fd(s, 1);
	tab->tl += tab->prc;
}

void	z_hex_printer(t_print *tab, char *s, int c)
{
	if (tab->ash)
		tab->wdt -= 2;
	ash_printer(tab, c);
	zero_printer((tab->wdt - tab->prc), tab);
	ft_putstr_fd(s, 1);
	tab->tl += tab->prc;
}

void	w_hex_printer(t_print *tab, char *s, int c, unsigned int n)
{
	if (tab->is_zero)
		tab->prc = 0;
	if (tab->ash && n == 0)
		tab->ash = 0;
	hex_wdt_manager(tab, s, c);
	if (!tab->is_zero)
		ft_putstr_fd(s, 1);
	hex_wdt_manager(tab, s, c);
	if (!tab->is_zero)
		tab->tl += ft_sstrlen(s);
}
