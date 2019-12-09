/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:53:22 by viroques          #+#    #+#             */
/*   Updated: 2019/12/09 21:00:37 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int		ft_printf(char *format, ...)
{
	va_list ap;
	int		i;
	int		r;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'd')
			{
				r = va_arg(ap, int);
				ft_putnbr_fd(r, 1);
			}
		}
		if (ft_isprint(format[i]))
			write(1, format[i], 1);
		if (format[i] == '\n')
			write(1, "\n", 1);
		i++;
	}
	va_end(ap);
	return (1);
}
