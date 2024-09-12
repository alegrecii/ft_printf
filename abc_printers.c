/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abc_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:13:16 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/21 17:17:25 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	special_putstr(char *s, t_print *tab)
{
	int	i;

	i = 0;
	while (i < tab->prc && s[i])
	{
		tab->tl += write(1, &s[i], 1);
		i++;
	}
}

void	char_printer(int c, t_print *tab)
{
	if (!tab->dash)
		space_printer((tab->wdt - 1), tab);
	ft_putchar_fd(c, 1);
	if (tab->dash)
		space_printer((tab->wdt -1), tab);
	tab->tl++;
}

static void	null_str_printer(t_print *tab)
{
	if ((tab->prc > 5 && tab->pnt) || !tab->pnt)
	{
		if (!tab->dash)
			space_printer((tab->wdt - 6), tab);
		tab->tl += write(1, "(null)", 6);
		if (tab->dash)
			space_printer((tab->wdt - 6), tab);
	}
	else
		space_printer(tab->wdt, tab);
}

void	str_printer(char *s, t_print *tab)
{
	if (!s)
	{
		null_str_printer(tab);
		return ;
	}
	if (!tab->pnt)
		tab->prc = ft_sstrlen(s);
	else
		if (ft_sstrlen(s) < tab->prc)
			tab->prc = ft_sstrlen(s);
	if (!tab->dash)
		space_printer((tab->wdt - tab->prc), tab);
	special_putstr(s, tab);
	if (tab->dash)
		space_printer((tab->wdt - tab->prc), tab);
}

void	ptr_printer(uintptr_t p, t_print *tab)
{
	char	*s;

	if (p == 0)
	{
		if (!tab->dash)
			space_printer(tab->wdt - 5, tab);
		tab->tl += write(1, "(nil)", 5);
		if (tab->dash)
			space_printer(tab->wdt - 5, tab);
		return ;
	}
	s = ft_itoa_base("0123456789abcdef", p);
	if (!tab->dash)
		space_printer((tab->wdt - (ft_sstrlen(s) + 2)), tab);
	tab->tl += write(1, "0x", 2);
	ft_putstr_fd(s, 1);
	if (tab->dash)
		space_printer((tab->wdt - (ft_sstrlen(s) + 2)), tab);
	tab->tl += ft_sstrlen(s);
	free (s);
}
