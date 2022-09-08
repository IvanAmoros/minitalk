/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:28:25 by iamoros-          #+#    #+#             */
/*   Updated: 2022/05/29 19:35:36 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **str, size_t x)
{
	while (x > 0)
	{
		x--;
		free(str[x]);
	}
	free(str);
}

static size_t	c_words(char const *s, char c)
{
	int		i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			w++;
		i++;
	}
	return (w);
}

static size_t	c_start(char const *s, char c, size_t start)
{
	while (s[start] == c)
		start++;
	return (start);
}

static int	ft_fill(char const *s, char **str, size_t w, char c)
{
	int		x;
	size_t	end;
	size_t	start;

	x = 0;
	start = 0;
	while ((size_t)x < w)
	{
		start = c_start(s, c, start);
		end = 0;
		while (s[start] != c && s[start] != '\0')
		{
			end++;
			start++;
		}
		str[x] = ft_substr(s, start - end, end);
		if (!str[x])
		{
			ft_free(str, x);
			return (-1);
		}	
		x++;
	}
	return (x);
}

char	**ft_split(char const *s, char c)
{
	size_t	w;
	int		x;
	char	**str;

	w = c_words(s, c);
	str = ((char **)malloc(sizeof(char *) * (w + 1)));
	if (!str)
		return (0);
	x = ft_fill(s, str, w, c);
	if (x == -1)
		return (NULL);
	str[x] = NULL;
	return (str);
}
