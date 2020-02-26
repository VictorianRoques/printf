/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_addr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:09:00 by viroques          #+#    #+#             */
/*   Updated: 2020/02/26 22:04:31 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_fill_string(uintptr_t n, int index, char *str, char *base)
{
	unsigned int base_len;

	base_len = (unsigned int)ft_strlen(base);
	if (n >= base_len)
		ft_fill_string(n / base_len, index - 1, str, base);
	str[index] = base[n % base_len];
}

char			*ft_itoa_base_addr(uintptr_t n, char *base)
{
	char			*str;
	uintptr_t		nbr;
	int				size;
	unsigned int	len_base;

	len_base = (unsigned int)ft_strlen(base);
	size = 1;
	nbr = n;
	while (nbr >= len_base)
	{
		nbr /= len_base;
		size++;
	}
	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	ft_fill_string(n, size - 1, str, base);
	return (str);
}
