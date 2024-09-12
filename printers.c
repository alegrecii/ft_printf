/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:39:29 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/21 17:40:59 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	space_printer(int n, t_print *tab)
{
	int	i;

	i = 0;
	while (i < n)
	{
		tab->tl += write(1, " ", 1);
		i++;
	}
}

void	zero_printer(int n, t_print *tab)
{
	int	i;

	i = 0;
	while (i < n)
	{
		tab->tl += write(1, "0", 1);
		i++;
	}
}

void	num_wdt_manager(t_print *tab, char *s)
{
	if (tab->dash == 2)
		space_printer((tab->wdt - tab->prc), tab);
	if (tab->dash == 1)
	{
		if ((tab->sign >= 0 && tab->plus) || (tab->sign < 0) || tab->sp)
			tab->wdt--;
		sign_printer(tab);
		zero_printer((tab->prc - ft_sstrlen(s)), tab);
		tab->dash = 2;
	}
	if (tab->dash == 0)
	{
		if ((tab->sign >= 0 && tab->plus) || (tab->sign < 0) || tab->sp)
			tab->wdt--;
		space_printer((tab->wdt - tab->prc), tab);
		sign_printer(tab);
		zero_printer((tab->prc - ft_sstrlen(s)), tab);
		tab->dash = 3;
	}
}

void	hex_wdt_manager(t_print *tab, char *s, int c)
{
	if (tab->dash == 2)
		space_printer((tab->wdt - tab->prc), tab);
	if (tab->dash == 1)
	{
		if (tab->ash)
			tab->wdt -= 2;
		ash_printer(tab, c);
		zero_printer((tab->prc - ft_sstrlen(s)), tab);
		tab->dash = 2;
	}
	if (tab->dash == 0)
	{
		if (tab->ash)
			tab->wdt -= 2;
		space_printer((tab->wdt - tab->prc), tab);
		ash_printer(tab, c);
		zero_printer((tab->prc - ft_sstrlen(s)), tab);
		tab->dash = 3;
	}
}
