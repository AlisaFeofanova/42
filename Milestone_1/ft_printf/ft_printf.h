/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printf.h                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>     +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/02/11 18:45:51 by alfeofan       #+#    #+#                */
/*   Updated: 2026/02/11 18:46:04 by alfeofan       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_puthex(unsigned int n, int upper);
int		ft_putptr(void *ptr);
int		ft_strlen(const char *s);

#endif
