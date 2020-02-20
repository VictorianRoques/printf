/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:33:58 by viroques          #+#    #+#             */
/*   Updated: 2020/02/20 22:37:29 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_s_conv(t_env *env, char *str)
{
	int			i;
	int			len;
	static char *null = "(null)";

	if (str == NULL)
		str = null;
	i = 0;
	if (env->width.precision < (int)ft_strlen(str) &&
			env->width.precision != -1)
		len = env->width.precision;
	else
		len = ft_strlen(str);
	ft_handle_buff(env, str, len);
	return (0);
}

int		ft_c_conv(t_env *env, int c)
{
	if (env->attributs.minus == true)
	{
		ft_fill_buff_c(env, (unsigned char)c);
		ft_fill_padding(env, env->width.padding - 1, ' ');
	}
	else
	{
		ft_fill_padding(env, env->width.padding - 1, ' ');
		ft_fill_buff_c(env, (unsigned char)c);
	}
	return (0);
}
