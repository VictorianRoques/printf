/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:56:23 by viroques          #+#    #+#             */
/*   Updated: 2019/12/17 23:57:06 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/ft_printf.h"
#include <stdio.h>

int		main()
{
	char *str = "bonjour";
	int s[10];

	*s = 10;
	printf("%p\n", str);
	ft_printf("%p\n", str);
	printf("%p\n", s);
	ft_printf("%p\n", s);

}
