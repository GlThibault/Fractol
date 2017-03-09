/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:02:09 by tglandai          #+#    #+#             */
/*   Updated: 2016/11/08 12:48:22 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbwords(char const *s, char c)
{
	int		nb_words;
	int		is_word;

	is_word = 1;
	nb_words = 0;
	while (*s != '\0')
	{
		if (is_word == 0 && *s == c)
			is_word = 1;
		if (is_word == 1 && *s != c)
		{
			is_word = 0;
			nb_words++;
		}
		s++;
	}
	return (nb_words);
}

static int	ft_wordlen(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		nb_words;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	nb_words = ft_nbwords(s, c);
	if ((str = (char **)malloc(sizeof(char *) * (nb_words + 1))) == NULL)
		return (NULL);
	while (nb_words)
	{
		while (*s == c && *s != '\0')
			s++;
		if ((str[i] = ft_strsub(s, 0, ft_wordlen(s, c))) == NULL)
			return (NULL);
		s += ft_wordlen(s, c);
		i++;
		nb_words--;
	}
	str[i] = NULL;
	return (str);
}
