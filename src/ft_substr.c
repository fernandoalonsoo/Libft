/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:37:14 by kali              #+#    #+#             */
/*   Updated: 2024/09/19 18:55:19 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *substr;
    size_t i;

    // Si la cadena original es NULL
    if (!s)
        return (NULL);
    // Si start es mayor que la propia cadena original
    if (start >= ft_strlen(s))
        return (ft_strdup(""));
    // Reservar memoria para la subcadena
    substr = (char *)malloc(sizeof(char) * (len + 1));
    if (!substr)
        return (NULL);
    // Copiar los caracteres de la subcadena
    i = 0;
    while (i < len && s[start + i])
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}
