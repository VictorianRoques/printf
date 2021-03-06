/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:11:57 by viroques          #+#    #+#             */
/*   Updated: 2020/02/26 21:51:33 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdbool.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"
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

typedef struct	s_conv
{
	char conv;
}				t_conv;

typedef struct	s_env
{
	char		buffer[BUFFER_SIZE];
	int			fd;
	size_t		buff_index;
	t_attributs	attributs;
	t_width		width;
	t_conv		conv;
	int			compt;
}				t_env;

int				ft_printf(char *format, ...);
int				ft_write_full_buff(t_env *env);
int				ft_fill_buff_c(t_env *env, unsigned char c);
void			ft_fill_buff_s(t_env *env, char *str, int len);
char			*ft_parse_attributs(char *str, t_env *env);
char			*ft_parse_width(char *str, t_env *env, va_list args);
char			*ft_parse_width_2(char *str, t_env *env, va_list args);
char			*ft_parse_length(char *str, t_env *env);
char			*ft_parse_conv(char *str, t_env *env);
int				ft_fill_padding(t_env *env, int len, char c);
int				ft_s_conv(t_env *env, char *str);
int				ft_c_conv(t_env *env, int c);
int				ft_x_conv(t_env *env, unsigned int nb);
int				ft_p_conv(t_env *env, uintptr_t *p);
int				ft_u_conv(t_env *env, unsigned int n);
int				ft_i_conv(t_env *env, int n);
int				ft_percent_conv(t_env *env);
void			ft_handle_buff_padding_int(t_env *env, int len, int negative);
void			ft_handle_buff_padding(t_env *env, int len);
void			ft_handle_buff(t_env *env, char *str, int len);
void			ft_handle_int(t_env *env, char *str, int len, int negative);
void			ft_handle_buff_padding_s(t_env *env, int len);

#endif
