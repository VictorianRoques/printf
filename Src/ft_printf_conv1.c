/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:33:58 by viroques          #+#    #+#             */
/*   Updated: 2019/12/18 00:02:57 by viroques         ###   ########.fr       */
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

int		ft_x_conv(t_env *env, unsigned int nb, int x)
{
	char	*str;
	int		len;

	if (x == 0)
		str = ft_itoa_base(nb, "0123456789abcdef");
	else
		str = ft_itoa_base(nb, "0123456789ABCDEF");
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
	return (0);
}

int		ft_p_conv(t_env *env, void *p)
{
	char	*str;
	int		len;
	// static char *hexa = "0x"
	// check ft_memory for right print hexa
	str = ft_itoa_base_unsigned((unsigned int)p, "0123456789abcdef");
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
	return (0);
}
