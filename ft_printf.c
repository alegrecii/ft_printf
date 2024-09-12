/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:42:08 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/21 17:29:35 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		ret;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	i = 0;
	ret = 0;
	tab->tl = 0;
	va_start(tab->args, format);
	while (format[i] != '\0')
	{
		ft_initialise_tab(tab);
		if (format[i] == '%')
			i = flag_manager(tab, format, i + 1);
		else
			ret = ret + write(1, &format[i], 1);
		i++;
	}
	va_end(tab->args);
	ret = ret + tab->tl;
	free (tab);
	return (ret);
}
