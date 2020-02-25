/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_padding.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:56:21 by viroques          #+#    #+#             */
/*   Updated: 2020/02/25 19:48:58 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_handle_buff_padding(t_env *env, int len)
{
	if (env->width.precision > len && env->conv.conv != 's')
		len = env->width.precision;
	if (env->attributs.zero == true)
	{
		if (env->width.precision >= 0 || env->attributs.minus == true)
			ft_fill_padding(env, env->width.padding - len, ' ');
		else
			ft_fill_padding(env, env->width.padding - len, '0');
	}
	else
		ft_fill_padding(env, env->width.padding - len, ' ');
}

void		ft_handle_buff(t_env *env, char *str, int len)
{
	if (env->attributs.minus == false)
	{
		ft_handle_buff_padding(env, len);
		ft_fill_padding(env, env->width.precision - len, '0');
		if (!(env->width.precision == 0 && str[0] == '0'))
			ft_fill_buff_s(env, str, len);
	}
	else
	{
		ft_fill_padding(env, env->width.precision - len, '0');
		if (!(env->width.precision == 0 && str[0] == '0'))
			ft_fill_buff_s(env, str, len);
		ft_handle_buff_padding(env, len);
	}
}

void		ft_handle_buff_padding_int(t_env *env, int len, int negative)
{
	if (env->width.precision > len && env->conv.conv != 's')
		len = env->width.precision;
	if (negative == 1)
		len += 1;
	if (env->attributs.zero == true)
	{
		if (env->width.precision >= 0 || env->attributs.minus == true)
			ft_fill_padding(env, env->width.padding - len, ' ');
		else
			ft_fill_padding(env, env->width.padding - len, '0');
	}
	else
		ft_fill_padding(env, env->width.padding - len, ' ');
}

void		ft_handle_int(t_env *env, char *str, int len, int negative)
{
	if (env->attributs.minus == false)
	{
		if (negative == 1 && env->width.precision < 0 && env->attributs.zero == true)
			ft_fill_buff_c(env, '-');
		ft_handle_buff_padding_int(env, len, negative);
		if ((negative == 1 && env->width.precision >= 0) || (negative == 1 && env->attributs.zero == false))
			ft_fill_buff_c(env, '-');
		ft_fill_padding(env, env->width.precision - len, '0');
		if (!(env->width.precision == 0 && str[0] == '0'))
			ft_fill_buff_s(env, str, len);
	}
	else
	{
		if (negative == 1)
			ft_fill_buff_c(env, '-');
		ft_fill_padding(env, env->width.precision - len, '0');
		if (!(env->width.precision == 0 && str[0] == '0'))
			ft_fill_buff_s(env, str, len);
		ft_handle_buff_padding_int(env, len, negative);
	}
}
