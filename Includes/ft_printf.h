/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:11:57 by viroques          #+#    #+#             */
/*   Updated: 2019/12/17 22:37:54 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdbool.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"
# define BUFFER_SIZE 2048

typedef struct	s_attributs
{
	bool zero;
	bool minus;
}				t_attributs;

typedef struct	s_width
{
	int padding;
	int precision;
}				t_width;

typedef struct s_length
{
	bool l;
	bool ll;
	bool h;
	bool hh;
}				t_length;

typedef struct s_conv
{
	char conv;
}				t_conv;

typedef struct s_env
{
	char	buffer[BUFFER_SIZE];
	int		fd;
	size_t	buff_index;
	t_attributs	attributs;
	t_width width;
	t_length length;
	t_conv conv;
}				t_env;

int		ft_printf(char *format, ...);
int			ft_write_full_buff(t_env *env);
int		ft_fill_buff_c(t_env *env, char c);
void		ft_fill_buff_s(t_env *env, char *str, int len);
char		*ft_parse_attributs(char *str, t_env *env);
char	*ft_parse_width(char *str, t_env *env, va_list args);
char	*ft_parse_length(char *str, t_env *env);
char		*ft_parse_conv(char *str, t_env *env);
int			ft_fill_padding(t_env *env, int len);
char	*ft_s_conv(t_env *env, char *str);
int		ft_c_conv(t_env *env, int c);
int		ft_x_conv(t_env *env, unsigned int);

#endif