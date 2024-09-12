/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:33:52 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/21 17:34:57 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	length(int n, t_print *tab)
{
	int	count;

	if (n == -2147483648)
		tab->sign = -1;
	count = 0;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	count++;
	return (count);
}

char	*ft_special_itoa(int n, t_print *tab)
{
	char	*str;
	int		i;

	i = length(n, tab);
	if (n == -2147483648)
		return (ft_strdup("2147483648"));
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		tab->sign = -1;
	}
	str[i] = '\0';
	i--;
	while (n > 9)
	{
		str[i] = (n % 10) + '0';
		i--;
		n /= 10;
	}
	str[i] = n + '0';
	return (str);
}

static int	u_length(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	count++;
	return (count);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*str;
	int		i;

	i = u_length(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	while (n > 9)
	{
		str[i] = (n % 10) + 48;
		i--;
		n /= 10;
	}
	str[i] = n + 48;
	return (str);
}

int	ft_sstrlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
