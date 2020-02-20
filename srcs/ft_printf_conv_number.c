/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:54:43 by viroques          #+#    #+#             */
/*   Updated: 2020/02/20 22:17:42 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_x_conv(t_env *env, unsigned int nb, int x)
{
	char	*str;
	int		len;

	if (x == 0)
		str = ft_itoa_base_unsigned(nb, "0123456789abcdef");
	else
		str = ft_itoa_base_unsigned(nb, "0123456789ABCDEF");
	len = ft_strlen(str);
	ft_handle_buff(env, str, len);
	free(str);
	return (0);
}

int		ft_p_conv(t_env *env, void *p)
{
	char		*str;
	int			len;

	str = ft_itoa_base_unsigned((long)p, "0123456789abcdef");
	len = ft_strlen(str) + 2;
	if (env->attributs.minus == true)
	{
		if (env->conv.conv != 's')
			ft_fill_padding(env, env->width.precision - len, '0');
		ft_fill_buff_s(env, "0x", 2);
		ft_fill_buff_s(env, str, len);
		ft_handle_buff_padding(env, len);
	}
	else
	{
		ft_handle_buff_padding(env, len);
		if (env->conv.conv != 's')
			ft_fill_padding(env, env->width.precision - len, '0');
		ft_fill_buff_s(env, "0x", 2);
		ft_fill_buff_s(env, str, len);
	}
	free(str);
	return (0);
}

int		ft_u_conv(t_env *env, unsigned int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	ft_handle_buff(env, str, len);
	free(str);
	return (0);
}

int		ft_i_conv(t_env *env, int n)
{
	char	*str;
	int		len;
	int		negative;

	negative = 0;
	if (n < 0)
	{
		n = -n;
		negative = 1;
	}
	str = ft_itoa((long)n);
	len = ft_strlen(str);
	ft_handle_int(env, negative, len, str);
	free(str);
	return (0);
}

int		ft_percent_conv(t_env *env)
{
	char str[2];

	str[0] = '%';
	str[1] = '\0';
	ft_handle_buff(env, str, 1);
	return (0);
}
