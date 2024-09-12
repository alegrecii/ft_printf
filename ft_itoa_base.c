/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:21:45 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/21 17:26:38 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32
			|| base[i] == 127)
			return (1);
		j = i +1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (1);
	if (base[0] == '\0')
		return (1);
	return (i);
}

static int	lenght_itoa(long unsigned int n, int size)
{
	int					f_lenght;
	long unsigned int	nb;

	f_lenght = 0;
	nb = n;
	while (nb >= (unsigned)size)
	{
		nb = nb / size;
		f_lenght++;
	}
	f_lenght++;
	return (f_lenght);
}

char	*ft_itoa_base(char *base_to, long unsigned int n)
{
	char				*final;
	long unsigned int	size;
	long unsigned int	nb;
	int					f_lenght;

	size = ft_check(base_to);
	f_lenght = lenght_itoa(n, size);
	nb = n;
	final = malloc(sizeof(char) * (1 + f_lenght));
	final[f_lenght] = '\0';
	f_lenght--;
	while (nb >= size)
	{
		final[f_lenght] = base_to[nb % size];
		nb = nb / size;
		f_lenght--;
	}
	final[f_lenght] = base_to[nb % size];
	return (final);
}
