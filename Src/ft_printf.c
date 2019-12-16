/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:53:22 by viroques          #+#    #+#             */
/*   Updated: 2019/12/16 18:59:52 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void			ft_init_struct(t_env *env)
{
	env->attributs.zero = false;
	env->attributs.minus = false;
	env->attributs.star = false;
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
	return (0);
}

char	*ft_s_conv(t_env *env, char *str)
{
	int i;
	int len;

	i = 0;
	if (env->width.precision < (int)ft_strlen(str) &&
			env->width.precision != -1)
		len = env->width.precision;
	else
		len = ft_strlen(str);
	if (env->attributs.minus == true)
	{
		ft_fill_buff_s(env, str, len);
		if (env->width.padding > len)
			ft_fill_padding(env, env->width.padding - len);
	}
	else
	{
		if (env->width.padding > len)
			ft_fill_padding(env, env->width.padding - len);
		ft_fill_buff_s(env, str, len);
	}
	return (str);
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
			format = ft_parse_width(format, &env);
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
