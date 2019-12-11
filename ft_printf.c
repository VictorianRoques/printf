/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:53:22 by viroques          #+#    #+#             */
/*   Updated: 2019/12/11 18:18:23 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

void	ft_init_struct(t_env *env)
{
	env->attributs.hashtag = false;
	env->attributs.zero = false;
	env->attributs.minus = false;
	env->attributs.blank = false;
	env->attributs.plus = false;
	env->attributs.percent = false;
	env->width.padding = 0;
	env->width.precision = -1;
	env->length.l = false;
	env->length.ll = false;
	env->length.h = false;
	env->length.hh = false;
	env->fd = 1;
}

int			ft_write_full_buff(t_env *env)
{
	if (env->buff_index == BUFFER_SIZE)
	{
		if (write(env->fd, env->buffer, env->buff_index) == -1)
			return (-1);
		env->buff_index = 0;
	}
	return (1);
}

int		ft_fill_buff_c(t_env *env, char c)
{
	if (ft_write_full_buff(env) == -1)
		return (-1);
	env->buffer[env->buff_index] = c;
	env->buff_index++;
	return (0);
}

void		ft_fill_buff_s(t_env *env, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (env->buff_index == BUFFER_SIZE)
			ft_write_full_buff(env);
		env->buffer[env->buff_index] = str[i];
		i++;
		env->buff_index++;
	}
}

char		*ft_parse_attributs(char *str, t_env *env)
{
	while (*str == '#' || *str == '0' || *str == '-'
			|| *str == ' ' || *str == '+')
	{
		if (*str == '#')
			env->attributs.hashtag = true;
		if (*str == '0')
			env->attributs.zero = true;
		if (*str == '-')
			env->attributs.minus = true;
		if (*str == '+')
			env->attributs.plus = true;
		if (*str == ' ')
			env->attributs.blank = true;
		// gerer %
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
	static char *tmp = "cspdiouxX";

	if (ft_strchr(tmp,  *str))
		env->conv.conv = *str;
	return (str);
}
int				ft_printf(char *format, ...)
{
	va_list		ap;
	t_env		env;
	size_t		i;

	i = 0;
	env.buff_index = 0;

	// ft_fill_buff_s(&env, format);
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
	printf("%d\n", env.attributs.zero);
	printf("%d\n", env.width.padding);
	printf("%c\n", env.conv.conv);
	// write(1, env.buffer, env.buff_index);
	return (1);
}