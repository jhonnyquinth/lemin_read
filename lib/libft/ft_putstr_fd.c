/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:37:18 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/18 17:16:49 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *str, int fd)
{
	int i;

	if (str)
	{
		i = 0;
		while (str[i] != '\0')
		{
			ft_putchar_fd(str[i], fd);
			i++;
		}
	}
}
