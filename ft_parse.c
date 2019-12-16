/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:39:28 by viroques          #+#    #+#             */
/*   Updated: 2019/12/14 19:47:46 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_parse_attributs(char *str, t_env *env)
{
	while (*str == '0' || *str == '-' || *str == '*')
	{
		if (*str == '*')
			env->attributs.star = true;
		if (*str == '0')
			env->attributs.zero = true;
		if (*str == '-')
			env->attributs.minus = true;
		str++;
	}
	return (str);
}

char	*ft_parse_width(char *str, t_env *env)
{
	char tmp[11];
	int	i;

	i = 0;
	if (*str >= '1' && *str <= '9')
	{
		while (ft_isdigit(*str))
		{
			tmp[i] = *str;
			i++;
			str++;
		}
		tmp[i] = '\0';
		env->width.padding = ft_atoi(tmp);
	}
	if (*str == '.')
	{
		i = 0;
		str++;
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

char	*ft_parse_length(char *str, t_env *env)
{
	if (*str == 'h')
	{
		if (*str + 1 == 'h')
		{
			env->length.hh = true;
			str++;
		}
		else
			env->length.h = true;
		str++;
	}
	else if (*str == 'l')
	{
		if (*str + 1 == 'l')
		{
			env->length.ll = true;
			str++;
		}
		else
			env->length.l = true;
		str++;
	}
	return (str);
}

char		*ft_parse_conv(char *str, t_env *env)
{
	static char *tmp = "cspdiuxX%";

	if (ft_strchr(tmp, *str))
		env->conv.conv = *str;
	return (str);
}
