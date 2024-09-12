/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:41:55 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/21 17:33:13 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_print{
	va_list	args;
	int		wdt;
	int		prc;
	int		zero;
	int		pnt;
	int		dash;
	int		tl;
	int		sign;
	int		is_zero;
	int		perc;
	int		sp;
	int		ash;
	int		plus;
}	t_print;
t_print	*ft_initialise_tab(t_print *tab);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strdup(const char *src);
char	*ft_special_itoa(int n, t_print *tab);
char	*ft_unsigned_itoa(unsigned int n);
int		flag_manager(t_print *tab, const char *format, int i);
int		ft_printf(const char *format, ...);
int		conv_check(char c);
void	z_int_printer(t_print *tab, char *s);
void	z_uns_printer(t_print *tab, char *s);
void	z_hex_printer(t_print *tab, char *s, int c);
void	w_hex_printer(t_print *tab, char *s, int c, unsigned int n);
void	zero_printer(int n, t_print *tab);
void	space_printer(int n, t_print *tab);
void	sign_printer(t_print *tab);
size_t	ft_strlen(const char *str);
void	int_printer(int n, t_print *tab);
void	uns_printer(unsigned int n, t_print *tab);
void	num_wdt_manager(t_print *tab, char *s);
char	*ft_itoa_base(char *base_to, long unsigned int n);
void	ash_printer(t_print *tab, int c);
void	hex_wdt_manager(t_print *tab, char *s, int c);
void	ptr_printer(uintptr_t p, t_print *tab);
void	hex_printer(unsigned int n, t_print *tab, int c);
void	str_printer(char *s, t_print *tab);
void	char_printer(int c, t_print *tab);
int		ft_atoi(const char *str);
int		ft_sstrlen(const char *s);
#endif
