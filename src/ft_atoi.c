/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:24:36 by fealonso          #+#    #+#             */
/*   Updated: 2024/09/19 18:03:17 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' 
        || c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int ft_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (is_space(str[i]))
        i++;

    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return (result * sign);
}
