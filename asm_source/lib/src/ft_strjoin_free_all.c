/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:34:34 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_all(char *s1, char *s2)
{
	char	*result;

	if (!s2)
		return (s1);
	result = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (result);
}
