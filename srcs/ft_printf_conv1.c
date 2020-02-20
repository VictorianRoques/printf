/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:33:58 by viroques          #+#    #+#             */
/*   Updated: 2020/02/20 16:25:30 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_handle_buff_padding(t_env *env, int len)
{
	if (env->width.precision > len && env->conv.conv != 's')
		len = env->width.precision;
	if (env->attributs.zero == true)
		ft_fill_padding(env, env->width.padding - len, '0');
	else
		ft_fill_padding(env, env->width.padding - len, ' ');
}

void		ft_handle_buff(t_env *env, char *str, int len)
{
	if (env->attributs.minus == true)
	{
		if (env->conv.conv != 's')
			ft_fill_padding(env, env->width.precision - len, '0');
		ft_fill_buff_s(env, str, len);
		ft_handle_buff_padding(env, len);
	}
	else
	{
		ft_handle_buff_padding(env, len);
		if (env->conv.conv != 's')
			ft_fill_padding(env, env->width.precision - len, '0');
		ft_fill_buff_s(env, str, len);
	}
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
	ft_handle_buff(env, str, len);
	return (str);
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

int		ft_x_conv(t_env *env, unsigned int nb, int x)
{
	char	*str;
	int		len;

	if (x == 0)
		str = ft_itoa_base(nb, "0123456789abcdef");
	else
		str = ft_itoa_base(nb, "0123456789ABCDEF");
	len = ft_strlen(str);
	ft_handle_buff(env, str, len);
	free(str);
	return (0);
}

int		ft_p_conv(t_env *env, void *p)
{
	char	*str;
	static char *hexa = "0x10";

	str = ft_itoa_base((unsigned int)p, "0123456789abcdef");
	ft_fill_buff_s(env, hexa, 4);
	ft_fill_buff_s(env, str, ft_strlen(str));
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

	str = ft_itoa(n);
	len = ft_strlen(str);

	ft_handle_buff(env, str, len);
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