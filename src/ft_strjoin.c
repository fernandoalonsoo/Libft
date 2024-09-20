/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:55:40 by kali              #+#    #+#             */
/*   Updated: 2024/09/19 19:15:27 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char    *p;
    size_t  len1;
    size_t  len2;
    size_t  i;
    size_t  j;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    // Sumamos longitudes +1 para el caracter nulo
    p = malloc(len1 + len2 + 1);
    i = 0;
    j = 0;
    if (p)
    {
        // Copiamos la primera parte
        while (i < len1)
            p[i] = s1[i++];
        // Copiamos la segunda cadena
        while (j < len2)
            p[i + j] = s2[j++];
        p[i + j] = '\0';
    }
    return (p);

}
