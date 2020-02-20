/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:56:23 by viroques          #+#    #+#             */
/*   Updated: 2020/02/20 22:56:04 by viroques         ###   ########.fr       */
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

		ft_printf("p0 % .3s\n", "cccc");
		ft_printf("pp %.50d\n", 10000);
		ft_printf("p1 %.4s\n", "cccc");
		ft_printf("p2 %.10s\n", "cccc");
		ft_printf("p3 %.4s\n", NULL);
		ft_printf("p4 %.5s\n", "aaaaa");
		ft_printf("p5 %.3d\n", 100);
		ft_printf("p6 %.0d\n", 100);
		ft_printf("p7 %.4d\n", 100);
		ft_printf("p8 %.10d\n", 100);
		ft_printf("p9 %.50d\n", 100);
		ft_printf("p10 %.1d\n", 100);
		ft_printf("p11 %.3d\n", 100);
		ft_printf("p12 %.0d\n", 0);
		ft_printf("p13 %.3i\n", 100);
		ft_printf("p14 %.0i\n", 100);
		ft_printf("p15 %.4i\n", 100);
		ft_printf("p16 %.10i\n", 100);
		ft_printf("p17 %.50i\n", 100);
		ft_printf("p18 %.1i\n", 100);
		ft_printf("p19 %.3x\n", 100);
		ft_printf("p20 %.0x\n", 0);
		ft_printf("p21 %.3x\n", 100);
		ft_printf("p22 %.0x\n", 100);
		ft_printf("p23 %.4x\n", 100);
		ft_printf("p24 %.10x\n", 100);
		ft_printf("p25 %.50x\n", 100);
		ft_printf("p26 %.1x\n", 100);
		ft_printf("p27 %.3x\n", 100);
		ft_printf("p28 %.0x\n", 0);
		ft_printf("p29 %.3u\n", 100);
		ft_printf("p30 %.0u\n", 100);
		ft_printf("p31 %.4u\n", 100);
		ft_printf("p32 %.10u\n", 100);
		ft_printf("p33 %.50u\n", 100);
		ft_printf("p34 %.1u\n", 100);
		ft_printf("p35 %.3u\n", 100);
		ft_printf("p36 %.0u\n", 0);
		ft_printf("%%\n");
		ft_printf("Hello 42 school! %s", NULL);
		ft_printf("%010%");
		ft_printf("%u", 4294967295);
		ft_printf("%d\n", 2147483647);
		ft_printf("%d\n", -2147483648);
		ft_printf("%x\n", 2147483647);
		ft_printf("%x\n", -2147483648);
		ft_printf("%X\n", 2147483647);
		ft_printf("%X\n", -2147483648);
		ft_printf("%x\n", 0);
		ft_printf("%010x\n", 0);
		ft_printf("%010x\n", 20);
		ft_printf("%010x\n", -20);
		ft_printf("%10x\n", 20);
		ft_printf("%10.2x\n", -20);
		ft_printf("%-10x\n", 50);
		ft_printf("%-15x\n", 0);
		ft_printf("%.1x\n", 500);
		ft_printf("%*.*x\n", 50, 10, 2);
		ft_printf("%x\n", -1);
		ft_printf("%");
		ft_printf("%40.50d\n", 50);
		ft_printf("%d\n", -589);
		ft_printf("%-4d\n", -2464);
		ft_printf("%.5d\n", -2372);
		ft_printf("%p\n", NULL);
		ft_printf("%015p\n", NULL);
		ft_printf("%15p\n", NULL);
		ft_printf("%-15p\n", NULL);
		ft_printf("ret = %d\n", ft_printf("%%p::[%010d]\n", -8473));
		ft_printf("ret = %d\n", ft_printf("%%p::[%10d]\n", -8473));
		ft_printf("ret = %d\n", ft_printf("%%p::[%.5d]\n", -8473));
		ft_printf("ret = %d\n", ft_printf("%%p::[%01.1d]\n", -8473));
		ft_printf("ret = %d\n", ft_printf("%%p::[%010.1d]\n", -8473));
		ft_printf("ret = %d\n", ft_printf("%%p::[%01.50d]\n", -8473));
		ft_printf("ret = %d\n", ft_printf("%%p::[%1.50d]\n", -8473));
		ft_printf("ret = %d\n", ft_printf("%%p::[%0100.50d]\n", -8473));
		ft_printf("ret = %d\n", ft_printf("%%p::[%010d]\n", 8473));
		ft_printf("ret = %d\n", ft_printf("%%p::[%10d]\n", 8473));
		ft_printf("ret = %d\n", ft_printf("%%p::[%.5d]\n", 8473));
		ft_printf("ret = %d\n", ft_printf("%%p::[%01.1d]\n", 8473));
		ft_printf("ret = %d\n", ft_printf("%%p::[%010.1d]\n", 8473));
		ft_printf("ret = %d\n", ft_printf("%%p::[%01.50d]\n", 8473));
		ft_printf("ret = %d\n", ft_printf("%%p::[%1.50d]\n", 8473));
		ft_printf("ret = %d\n", ft_printf("%%p::[%0100.50d]\n", 8473));
		ft_printf("%c", 'a');
		ft_printf("%10c", 't');
		ft_printf("%1c", 'y');
		ft_printf("%010c", 't');
		ft_printf("%50.2s", "Coucou");
		ft_printf("%50.2s", NULL);
		ft_printf("%5.0s", "Hello");
		ft_printf("%.1s", "Test");
		ft_printf("%10s", NULL);
		ft_printf("%10s", "Ok");
		ft_printf("%d\n", ft_printf("Les bornes :  %d, %d\n", -2147483648, 2147483647));
		ft_printf("%d\n", ft_printf("Les bornes :  %u, %u\n", 0, 4294967295));
		ft_printf("%d\n", ft_printf("Les bornes :  %x, %x\n", 0, 4294967295));
		ft_printf("%d\n", ft_printf("1chiffre 1 %d chiffre 2 %d\n", 42, -42));
		ft_printf("%d\n", ft_printf("2chiffre 1 %   d chiffre 2 % d\n", 42, -42));
		ft_printf("%d\n\n", ft_printf("4chiffre 1 %-12d chiffre 2 %-12d\n\n", 42, -42));
		ft_printf("%    i\n", -60);
		ft_printf("%   i\n", -60);
		ft_printf("%1p\n", &t);
		ft_printf("%1p\n", &t);
		ft_printf("t1 %050d\n", 10);
		ft_printf("t2 %-50d\n", 10);
		ft_printf("t3 %50.0d\n", 10);
		ft_printf("t4 %50.50d\n", 10);
		ft_printf("t5 %50.10d\n", 10);
		ft_printf("t6 %*.*d\n", 50,  5, 10);
		ft_printf("t7 %1.50d\n", -10);
		ft_printf("t8 %1.50d\n", 10);
		ft_printf("t9 %2.2d\n", 10);
		ft_printf("t10 %2.2d\n", -10);
		ft_printf("t12 %.0d\n", 0);
		ft_printf("t13 %01d\n", -20);
		ft_printf("t14 %10d\n", 1000);
		ft_printf("%d\n\n", ft_printf("5chiffre 1 %0d chiffre 2 %0d\n\n", 42, -42));
		ft_printf("%d\n\n", ft_printf("6chiffre 1 %012d chiffre 2 %012d\n\n", 42, -42));
		ft_printf("%d\n\n", ft_printf("8chiffre 1 %*d chiffre 2 %*d\n\n", 42, 6, 6, 6));
		ft_printf("%d\n\n", ft_printf("15chiffre 1 %.d chiffre 2 %.d\n\n", 42, -42));
		ft_printf("%d\n\n", ft_printf("4caractere 1 %12c caractere 2 %12c\n\n", 'a', 'c'));
		ft_printf("1caractere 1 %c caractere 2 %c\n\n", 'a', 'c');
		ft_printf("3caractere 1 %   c caractere 2 % c\n\n", 'a', 'c');
		ft_printf("%d\n\n", ft_printf("1hexa-maj 1 %X hexa-maj 2 %X\n\n", 42, -42));
		ft_printf("%d\n\n", ft_printf("3hexa-maj 1 %   X hexa-maj 2 % X\n\n", 42, -42));
		ft_printf("%d\n\n", ft_printf("4hexa-maj 1 %12X hexa-maj 2 %int12X\n\n", 42, -42));
		ft_printf("%d\n\n", ft_printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n\n", 42, -42));
		ft_printf("%d\n\n", ft_printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n\n", 42, -42));
		ft_printf("%d\n\n", ft_printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n\n", 42, -42));
		ft_printf("%d\n\n", ft_printf("8hexa-maj 1 %*X hexa-maj 2 %*X\n\n", 42, 6, 6, 6));
		ft_printf("%d\n\n", ft_printf("1pointeur 1 %p pointeur 2 %p\n\n", &c, &c));
		ft_printf("%d\n\n", ft_printf("3pointeur 1 %   p pointeur 2 % p\n\n", &c, &c));
		ft_printf("%d\n\n", ft_printf("4pointeur 1 %12p pointeur 2 %12p\n\n", &c, &c));
		ft_printf("%d\n\n", ft_printf("4pointeur 1 %-12p pointeur 2 %-12p\n\n", &c, &c));
		ft_printf("%d\n\n", ft_printf("5pointeur 1 %0p pointeur 2 %0p\n\n", &c, &c));
		ft_printf("%d\n\n", ft_printf("6pointeur 1 %012p pointeur 2 %012p\n\n", &c, &c));
		ft_printf("%d\n\n", ft_printf("1unsigned 1 %u unsigned 2 %u\n\n", 42, -42));
		ft_printf("%d\n\n", ft_printf("3unsigned 1 %   u unsigned 2 % u\n\n", 42, -42));
		ft_printf("%d\n\n", ft_printf("4unsigned 1 %12u unsigned 2 %12u\n\n", 42, -42));
		ft_printf("%d\n\n", ft_printf("4unsigned 1 %-12u unsigned 2 %-12u\n\n", 42, -42));
		ft_printf("%d\n\n", ft_printf("5unsigned 1 %0u unsigned 2 %0u\n\n", 42, -42));
		ft_printf("%d\n\n", ft_printf("6unsigned 1 %012u unsigned 2 %012u\n\n", 42, -42));
		ft_printf("%d\n\n", ft_printf("8unsigned 1 %*u unsigned 2 %*u\n\n", 42, 6, 6, 6));
		ft_printf("%d\n\n", ft_printf("15unsigned 1 %.u unsigned 2 %.u\n\n", 42, -42));
		ft_printf("%d\n\n", ft_printf("%s", 0));
		ft_printf("%d\n\n", ft_printf("%%\n")); 
		ft_printf("%d\n\n", ft_printf("%-.12u\n", -20000000));
		ft_printf("%d\n\n", ft_printf("%-.12i\n", -20000000));
		ft_printf("%d\n", ft_printf("truc"));
		ft_printf("%d\n", ft_printf("bonjour !\n", 42, -42));
		ft_printf("04 Test de chiffre sans h : %d, et %d\n", 432767, -432767);
		ft_printf("%d\n", ft_printf("03 This is a float : %f\n\n", 45.236));
		ft_printf("%d\n", ft_printf("02 This is a float : %.3f\n\n", 45.236));
		ft_printf("%d\n",   ft_printf("01 This is a float : %3f\n\n", 45.236));
		ft_printf("%d\n", ft_printf("000 This is a float : %f\n\n", -45.236));
		ft_printf("%d\n", ft_printf("0 This is a float : %.3f\n\n", -45.236));
		ft_printf("%d\n", ft_printf("00 This is a float : %3f\n\n", -45.236));
		ft_printf("1 This is a float : %f\n\n", 0.00025);
		ft_printf("2 This is a float : %.3f\n\n", 0.00025);
		ft_printf("3 This is a float : %3f\n\n", 0.00025);
		ft_printf("4 This is a float : %f\n\n", -0.00025);
		ft_printf("5 This is a float : %f\n\n", -0.00025);
		ft_printf("6 This is a float : %.3f\n\n", -0.00025);
		ft_printf("7 This is a float : %3f\n\n", -0.00025);
		ft_printf("8 This is a float : %3f\n\n", 1.0 / 0.0);
		ft_printf("9 This is a float : %3f\n\n", -1.0 / 0.0);
		ft_printf("10 This is a float : %3f\n\n", 0.0 / 0.0);
		ft_printf("11 This is a float : %3f\n\n", -0.0 / 0.0);

}
