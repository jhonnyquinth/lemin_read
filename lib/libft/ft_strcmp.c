/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:44:07 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/07 18:29:44 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char c1;
	unsigned char c2;

	c1 = *s1;
	c2 = *s2;
	while (c1 == c2 && (c1 != '\0' || c2 != '\0'))
	{
		s1++;
		s2++;
		c1 = *s1;
		c2 = *s2;
	}
	return (c1 - c2);
}
