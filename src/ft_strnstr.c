/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:36:40 by fealonso          #+#    #+#             */
/*   Updated: 2024/09/17 15:37:33 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char * ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;
    size_t k;
    
    i = 0;
    if (little[i] == '\0')
        return ((char *) big);
    while (big[i] && i < len)
    {
        j = 0;
        if (big[i] == little[j])
        {
            k = i;

            // Comprobamos que sigan siendo iguales y que recorremos todo little sin pasarnos de len
            while (big[k] == little[j] && little[j] && k < len) 
            {
                k++;
                j++;
            }
            if (little[j] == '\0')
                return (&big[i]);
        }
        i++;
    }
    return (NULL);
}
