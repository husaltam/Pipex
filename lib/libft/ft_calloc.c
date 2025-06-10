/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:29:27 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/19 16:29:35 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned int count, unsigned int size)
{
	unsigned char	*pointer;
	unsigned int	total_size;
	unsigned int	i;

	total_size = count * size;
	pointer = (unsigned char *)malloc(total_size);
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < total_size)
		pointer[i++] = '\0';
	return (pointer);
}
