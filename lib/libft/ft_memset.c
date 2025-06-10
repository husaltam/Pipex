/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:35:33 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/19 16:35:42 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	value;

	ptr = str;
	value = (unsigned char)c;
	while (len--)
		*ptr++ = value;
	return (str);
}
