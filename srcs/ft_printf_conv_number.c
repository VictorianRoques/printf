/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:54:43 by viroques          #+#    #+#             */
/*   Updated: 2020/02/26 22:55:10 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_x_conv(t_env *env, unsigned int nb)
{
	char	*str;
	int		len;

	if (env->conv.conv == 'x')
		str = ft_itoa_base_unsigned(nb, "0123456789abcdef");
	else
		str = ft_itoa_base_unsigned(nb, "0123456789ABCDEF");
	if (!str)
		return (-1);
	if (env->width.precision == 0 && str[0] == '0')
		len = 0;
	else
		len = ft_strlen(str);
	ft_handle_buff(env, str, len);
	free(str);
	return (0);
}

int		ft_u_conv(t_env *env, unsigned int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	if (env->width.precision == 0 && str[0] == '0')
		len = 0;
	else
		len = ft_strlen(str);
	ft_handle_buff(env, str, len);
	free(str);
	return (0);
}

int		ft_i_conv(t_env *env, int n)
{
	char			*str;
	int				len;
	int				negative;
	unsigned int	nbr;

	negative = 0;
	if (n < 0)
	{
		nbr = -n;
		negative = 1;
	}
	else
		nbr = n;
	if (!(str = ft_itoa((long)nbr)))
		return (-1);
	if (env->width.precision == 0 && str[0] == '0')
		len = 0;
	else
		len = ft_strlen(str);
	ft_handle_int(env, str, len, negative);
	free(str);
	return (0);
}

int		ft_p_conv(t_env *env, uintptr_t *p)
{
	char		*str;
	int			len;

	if (!(str = ft_itoa_base_addr((uintptr_t)p, "0123456789abcdef")))
		return (-1);
	len = ft_strlen(str) + 2;
	if (env->attributs.minus == false)
	{
		ft_handle_buff_padding(env, len);
		ft_fill_buff_s(env, "0x", 2);
		if (p)
			ft_fill_buff_s(env, str, len);
	}
	else
	{
		ft_fill_buff_s(env, "0x", 2);
		if (p)
			ft_fill_buff_s(env, str, len);
		ft_handle_buff_padding(env, len);
	}
	free(str);
	return (0);
}
