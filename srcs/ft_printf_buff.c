/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:38:11 by viroques          #+#    #+#             */
/*   Updated: 2020/02/20 16:01:30 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	env->compt++;
	return (0);
}

int			ft_fill_padding(t_env *env, int len, char c)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_fill_buff_c(env, c);
		i++;
	}
	return (0);
}

void		ft_fill_buff_s(t_env *env, char *str, int len)
{
	int i;

	i = 0;
	while (str[i] && i < len)
	{
		if (env->buff_index == BUFFER_SIZE)
			ft_write_full_buff(env);
		env->buffer[env->buff_index] = str[i];
		i++;
		env->buff_index++;
		env->compt++;
	}
}
