/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:38:27 by swarner           #+#    #+#             */
/*   Updated: 2019/12/04 17:29:07 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	simple_error(char *error_text)
{
	ft_putstr("[!] Error: ");
	ft_putendl(error_text);
	exit(1);
}

void	error_exit(t_pasm *pasm, char *error_text)
{
	ft_putstr("[!] Error: ");
	ft_putendl(error_text);
	free_pasm(pasm);
	exit(1);
}

void	error_exit_line(t_pasm *pasm, t_code *code_line,
		char *error_text, int line_number)
{
	if (!code_line || code_line) // !!! исправить !!!
		ft_putstr("[!] ");
	ft_putstr("Error: line - ");
	ft_putnbr(line_number);
	ft_putstr(", ");
	ft_putendl(error_text);
	free_pasm(pasm);
	exit(1);
}
