/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:39:28 by viroques          #+#    #+#             */
/*   Updated: 2020/02/25 02:36:06 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_parse_attributs(char *str, t_env *env)
{
	while (*str == '0' || *str == '-')
	{
		if (*str == '0')
			env->attributs.zero = true;
		if (*str == '-')
			env->attributs.minus = true;
		str++;
	}
	return (str);
}

char		*ft_parse_width(char *str, t_env *env, va_list args)
{
	char	tmp[11];
	int		i;

	i = 0;
	if (*str == '*')
	{
		env->width.padding = va_arg(args, int);
		if (env->width.padding < 0)
		{
			env->width.padding = env->width.padding * -1;
			env->attributs.minus = true;
		}
		str++;
	}
	else if (*str >= '1' && *str <= '9')
	{
		while (ft_isdigit(*str))
			tmp[i++] = *str++;
		tmp[i] = '\0';
		env->width.padding = ft_atoi(tmp);
	}
	return (ft_parse_width_2(str, env, args));
}

char		*ft_parse_width_2(char *str, t_env *env, va_list args)
{
	char	tmp[11];
	int		i;

	i = 0;
	if (*str == '.')
	{
		i = 0;
		str++;
		if (*str == '*')
		{
			env->width.precision = va_arg(args, int);
			return (str + 1);
		}
		while (ft_isdigit(*str))
		{
			tmp[i] = *str;
			i++;
			str++;
		}
		tmp[i] = '\0';
		env->width.precision = ft_atoi(tmp);
	}
	return (str);
}

char		*ft_parse_conv(char *str, t_env *env)
{
	static char *tmp = "%cspdiuxX";

	if (ft_strchr(tmp, *str))
		env->conv.conv = *str;
	return (str);
}
