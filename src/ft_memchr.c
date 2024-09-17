/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:36:07 by fealonso          #+#    #+#             */
/*   Updated: 2024/09/17 15:36:08 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void *memchr(const void *s, int c, size_t n)
{
    int i;
    char *p;

    i = 0;
    p = (char *)s;
    while (i < n)
    {
        if(p[i] == c)
        {
            return (&p[i]);
        }
    i++;
    }
    return (NULL);
}
