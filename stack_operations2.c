/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:39:51 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/21 17:24:20 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//ra: Fait une rotation vers le haut de la pile a:
// le premier élément devient le dernier.
void ra(t_stack **a)
{
	if (!*a)
		return;
	t_stack *elem1;
	t_stack *tmp;
	
	elem1 = *a;
	*a = (*a)->next;
	tmp = *a;
	while (tmp && tmp->next) 
		tmp = tmp->next;
	tmp->next = elem1;
	elem1->next = NULL;
	ft_putstr_fd("ra\n", 1);
}

//ra: Fait une rotation vers le haut de la pile b:
// le premier élément devient le dernier.
void rb(t_stack **b)
{
	if (!*b)
		return;
	t_stack *elem1;
	t_stack *tmp;
	
	elem1 = *b;
	*b = (*b)->next;
	tmp = *b;
	while (tmp && tmp->next) 
		tmp = tmp->next;
	tmp->next = elem1;
	elem1->next = NULL;
	ft_putstr_fd ("rb\n", 1);
}

//rra: Fait une rotation vers le bas de la pile a.
// Le dernier élément devient le premier.
void rra(t_stack **a)
{
	if (ft_lstlen(*a) <= 1)
		return;
	t_stack *tmp;
	t_stack *bflast;

	tmp = *a;
	
	while (tmp && tmp->next) 
	{
		bflast = tmp;
		tmp = tmp->next;
	}
	bflast->next = NULL;
	tmp->next = *a;
	*a = tmp;
	ft_putstr_fd ("rra\n", 1);
}

void rrb(t_stack **b)
{
	if (ft_lstlen(*b) <= 1)
		return;
	t_stack *tmp;
	t_stack *bflast;

	tmp = *b;
	
	while (tmp && tmp->next) 
	{
		bflast = tmp;
		tmp = tmp->next;
	}
	bflast->next = NULL;
	tmp->next = *b;
	*b = tmp;
	ft_putstr_fd ("rrb\n",1);
}