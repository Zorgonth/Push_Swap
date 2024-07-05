/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:27:12 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/09/19 11:17:33 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (dest_len > dstsize)
		return (dstsize + src_len);
	while (src[i] && dest_len + i < dstsize - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	unsigned int	i;
	size_t			src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (destsize == 0)
		return (src_len);
	while (src[i] && i < destsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char		*str;
	size_t		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	str = (char *)malloc(len);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	str[ft_strlen(s1)] = ' ';
	str[ft_strlen(s1) + 1] = '\0';
	free(s1);
	ft_strlcat(str, s2, len);
	return (str);
}

char	**args(int argc, char **argv)
{
	int		i;
	char	*tmp;

	tmp = malloc(1);
	if (!tmp)
		return (NULL);
	i = 1;
	while (argv[i])
		tmp = ft_strjoin(tmp, argv[i++]);
	fix_args(argc, tmp);
	free(tmp);
	return (NULL);
}
