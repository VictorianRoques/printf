/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:56:23 by viroques          #+#    #+#             */
/*   Updated: 2020/02/14 01:31:48 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/ft_printf.h"
#include <stdio.h>

int		main()
{
	char *str = "bonjour";
	int s[10];

	*s = 10;
	// ft_printf("%-*.*d\n",10, 20, 10);
	// printf("%-*.*d\n",10, 20, 10);

	// ft_printf("%.5s\n", str);
	// printf("%.5s\n", str);

	// ft_printf("%-10.2i\n", 18745);
	printf("%-10.2i\n", 18745);
}