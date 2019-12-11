/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:11:57 by viroques          #+#    #+#             */
/*   Updated: 2019/12/11 18:18:22 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdbool.h>
# include <unistd.h>
# include <libft.h>
# define BUFFER_SIZE 10

typedef struct	s_attributs
{
	bool hashtag;
	bool zero;
	bool minus;
	bool blank;
	bool plus;
	bool percent;
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

#endif