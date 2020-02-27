/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:56:23 by viroques          #+#    #+#             */
/*   Updated: 2020/02/27 20:54:27 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/ft_printf.h"
#include <stdio.h>

int		main()
{
	int t;
	char c;

	c = 'a';
	t = 50;
	
	// ft_printf("|%15.6p|\n", "bonjour");
	// printf("|%15.6p|\n", "bonjour");

	// printf("fake %i", ft_printf("|%15.6p|\n", NULL));
	// printf("true %i", printf("|%15.6p|\n", NULL));

	ft_printf("|%p|\n", NULL);
	printf("|%p|\n", NULL);

}
