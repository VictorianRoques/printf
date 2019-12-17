/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:53:22 by viroques          #+#    #+#             */
/*   Updated: 2019/12/17 22:35:45 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void			ft_init_struct(t_env *env)
{
	env->attributs.zero = false;
	env->attributs.minus = false;
	env->width.padding = 0;
	env->width.precision = -1;
	env->length.l = false;
	env->length.ll = false;
	env->length.h = false;
	env->length.hh = false;
	env->fd = 1;
}

int				ft_read_conv(va_list args, t_env *env)
{
	if (env->conv.conv == 's')
		ft_s_conv(env, va_arg(args, char*));
	if (env->conv.conv == 'c')
		ft_c_conv(env, va_arg(args, int));
	if (env->conv.conv == 'x')
		ft_x_conv(env, va_arg(args, unsigned int));
	return (0);
}

int				ft_printf(char *format, ...)
{
	va_list		args;
	t_env		env;

	env.buff_index = 0;
	va_start(args, format);
	while (*format)
	{
		ft_init_struct(&env);
		if (*format == '%')
		{
			format++;
			format = ft_parse_attributs(format, &env);
			format = ft_parse_width(format, &env, args);
			format = ft_parse_length(format, &env);
			format = ft_parse_conv(format, &env);
			ft_read_conv(args, &env);
		}
		else
			ft_fill_buff_c(&env, *format);
		format++;
	}
	va_end(args);
	write(1, env.buffer, env.buff_index);
	return (1);
}
