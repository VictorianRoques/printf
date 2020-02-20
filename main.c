/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:56:23 by viroques          #+#    #+#             */
/*   Updated: 2020/02/20 16:47:47 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/ft_printf.h"
#include <stdio.h>

int		main()
{
	char *str = "bonjour";
	int s[10];
	char *test = "cspdiuxX%";
	*s = 10;
	// ft_printf("%-*.*d\n",10, 20, 10);
	// printf("%-*.*d\n",10, 20, 10);

	// ft_printf("%.5s\n", str);
	// printf("%.5s\n", str);

	// ft_printf("%-10.6s\n", str);
	// printf("%-10.6s\n", str);

	// printf("%p\n", str);
	// ft_printf("%p\n", str);
	// ft_printf("^.^/%c^.^/",(char)50);

	ft_printf("%040x\n", 4294967295);
	printf("%040x\n", 4294967295);
}