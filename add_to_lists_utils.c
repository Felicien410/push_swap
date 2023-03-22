/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_lists_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:03:03 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/22 17:01:28 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verif_all(t_stack **first, long long value)
{
	verif_integers(value);
	verif_double (*first, value);
}

void	add_to_list(t_stack **first, long long value)
{
	t_stack	*new_cell;
	t_stack	*current;
	t_stack	*prev;

	verif_all(first, value);
	new_cell = malloc (sizeof (t_stack));
	if (!new_cell)
		exit (0);
	new_cell->content = value;
	new_cell->next = NULL;
	new_cell->prec = NULL;
	if (!(*first))
		*first = new_cell;
	else
	{
		current = *first;
		prev = NULL;
		while (current)
		{
			prev = current;
			current = current->next;
		}
		prev->next = new_cell;
		new_cell->prec = prev;
	}
}

void	ft_print_list(t_stack *lst)
{
	t_stack	*current;

	current = lst;
	while (current != NULL)
	{
		printf("%lld\n", current->content);
		current = current->next;
	}
}

void	verif_double(t_stack *lst, long long nb)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->content == nb)
			ft_put_error();
		lst = lst->next;
		i++;
	}
}

void	verif_integers(long long value)
{
	if (value > 2147483647 || value < -2147483648)
		ft_put_error();
}
