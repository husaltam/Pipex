/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:37:50 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/19 16:37:54 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	dst_len;
	size_t	src_len;
	char	*result;
	char	*string;

	dst_len = ft_strlen(s1);
	src_len = ft_strlen(s2);
	result = (char *)malloc(dst_len + src_len + 1);
	string = result;
	if (!result)
		return (NULL);
	while (*s1)
		*result++ = *s1++;
	while (*s2)
		*result++ = *s2++;
	*result = '\0';
	return (string);
}
