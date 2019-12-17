/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:33:58 by viroques          #+#    #+#             */
/*   Updated: 2019/12/17 12:53:12 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		ft_c_conv(t_env *env, int c)
{
	if (env->attributs.minus == true)
	{
		ft_fill_buff_c(env, (unsigned char)c);
		ft_fill_padding(env, env->width.padding - 1);
	}
	else
	{
		ft_fill_padding(env, env->width.padding - 1);
		ft_fill_buff_c(env, (unsigned char)c);
	}
	return (0);
}
