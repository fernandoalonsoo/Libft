/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:30:47 by fealonso          #+#    #+#             */
/*   Updated: 2024/09/22 20:33:54 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count_words(char const *s, char c)
{
	int		i;
	int		count;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*copy_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**create_array(int count)
{
	return ((char **)malloc((count + 1) * sizeof(char *)));
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;
	int		in_word;

	array = create_array(count_words(s, c));
	if (!s || !(array))
		return (NULL);
	i = 0;
	j = 0;
	in_word = -1;
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] != c && in_word < 0)
			in_word = i;
		else if ((s[i] == c || i == (int)ft_strlen(s)) && in_word >= 0)
		{
			array[j++] = copy_word(s, in_word, i);
			in_word = -1;
		}
		i++;
	}
	array[j] = 0;
	return (array);
}
