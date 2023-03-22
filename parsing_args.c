/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:07:09 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/22 20:44:02 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_error (void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

long long help_atoi(const char *str, int i, long long result)
{
	if (ft_isdigit (str[i]) == 1)
	{
		result = result * 10 + str[i] - '0';
		i ++;
	}
	else
		ft_put_error();
	return (result);
}

long long 	ft_atoi_ps(const char *str)
{
	int	i;
	int	neg;
	long long 	result;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		neg *= -1;
		i ++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		result = help_atoi(str, i, result);
		i++;
	}
	return (result * neg);
}

t_stack	*split_and_replace(char *str,t_stack **a)
{
	char **tab;
	size_t	i;
	long long  content;
	
	i = 0;
	tab = ft_split(str, ' ');
	while(tab[i])
	{
		content = ft_atoi_ps(tab[i]);
		add_to_list(a, content);
		i++;
	}
	return (*a);
}