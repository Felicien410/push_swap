/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_fonctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:07:09 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/22 16:58:47 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeList(t_stack *stack)
{
	t_stack *tmp = NULL;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = NULL;
		stack = tmp;
	}
}

int	ft_lstlen(t_stack *lst)
{
	int i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		if (lst->next == NULL)
			return (i);
		lst = lst->next;
	}
	return (i);
}
