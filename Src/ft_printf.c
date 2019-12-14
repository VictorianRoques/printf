/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:53:22 by viroques          #+#    #+#             */
/*   Updated: 2019/12/14 19:28:30 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void		ft_init_struct(t_env *env)
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

int				ft_printf(char *format, ...)
{
	// va_list		ap;
	t_env		env;
	size_t		i;

	i = 0;
	env.buff_index = 0;

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
		}
		format++;
	}
	// printf("%d\n", env.attributs.zero);
	// printf("%d\n", env.width.padding);
	// printf("%c\n", env.conv.conv);
	return (1);
}