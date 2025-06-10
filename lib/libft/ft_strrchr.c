/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:39:40 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/19 16:39:44 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		ch;
	const char	*last_occurrence;

	ch = (char)c;
	last_occurrence = NULL;
	while (*s != '\0')
	{
		if (*s == ch)
			last_occurrence = s;
		s++;
	}
	if (*s == ch)
		last_occurrence = s;
	return ((char *)last_occurrence);
}
