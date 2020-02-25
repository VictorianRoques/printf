/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:53:22 by viroques          #+#    #+#             */
/*   Updated: 2020/02/25 20:14:43 by viroques         ###   ########.fr       */
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
	env->fd = 1;
}

int				ft_read_conv(va_list args, t_env *env)
{
	if (env->conv.conv == 's')
		return (ft_s_conv(env, va_arg(args, char*)));
	if (env->conv.conv == 'c')
		return (ft_c_conv(env, va_arg(args, int)));
	if (env->conv.conv == 'x' || env->conv.conv == 'X')
		return (ft_x_conv(env, va_arg(args, unsigned int)));
	if (env->conv.conv == 'p')
		return (ft_p_conv(env, va_arg(args, void*)));
	if (env->conv.conv == 'u')
		return (ft_u_conv(env, va_arg(args, unsigned int)));
	if (env->conv.conv == 'i' || env->conv.conv == 'd')
		return (ft_i_conv(env, va_arg(args, int)));
	if (env->conv.conv == '%')
		return (ft_percent_conv(env));
	return (0);
}

int				ft_printf(char *format, ...)
{
	va_list		args;
	t_env		env;

	env.buff_index = 0;
	env.compt = 0;
	va_start(args, format);
	while (*format)
	{
		ft_init_struct(&env);
		if (*format == '%')
		{
			format++;
			format = ft_parse_attributs(format, &env);
			format = ft_parse_width(format, &env, args);
			format = ft_parse_conv(format, &env);
			if ((ft_read_conv(args, &env) == -1))
				return (-1);
		}
		else
			ft_fill_buff_c(&env, *format);
		format++;
	}
	va_end(args);
	write(1, env.buffer, env.buff_index);
	return (env.compt);
}
