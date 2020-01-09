/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:23:03 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 13:23:04 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	print_error_and_exit(char *errstr, int errno)
{
	printf("%s\n", errstr);
	exit(errno);
}

void	print_usage(void)
{
	printf("Usage: ./corewar [-v][-d <num> ");
	printf("| -n <num> ] <champion1.cor> <...>\n");
	exit(1);
}
