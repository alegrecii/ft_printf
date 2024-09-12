/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:22:17 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/21 17:23:02 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->dash = 0;
	tab->is_zero = 0;
	tab->perc = 0;
	tab->pnt = 0;
	tab->prc = 0;
	tab->sign = 0;
	tab->sp = 0;
	tab->zero = 0;
	tab->ash = 0;
	tab->plus = 0;
	return (tab);
}
