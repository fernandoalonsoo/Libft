/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:36:13 by fealonso          #+#    #+#             */
/*   Updated: 2024/09/17 15:36:14 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int memcmp(const void *s1, const void *s2, size_t n)
{
    int i;
    unsigned char * p;
    unsigned char * q;

    i = 0;
    p = (unsigned char *) s1;
    q = (unsigned char *) s2;

    while(i < n)
    {
        if (p[i] != q[i])
            return (p[i] - q[i]);
        i++;
    }
    return (0);
}
