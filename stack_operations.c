/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:17:23 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/21 17:24:41 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Intervertit les 2 premiers éléments au sommet de la pile a.
//Ne fait rien s’il n’y en a qu’un ou aucun.
void	sa(t_stack **a)
{
	if (ft_lstlen(*a) < 2)
		return;

	t_stack *elem1;
	t_stack *elem2;
	long long	tmp;

	elem1 = *a;
	elem2 = elem1->next;
	tmp = elem1->content;
	elem1->content = elem2->content;
	elem2->content = tmp;
	ft_putstr_fd ("sa\n", 1);
	return ;
}

void sb(t_stack **b)
{
	if (ft_lstlen(*b) < 2)
	return;

	t_stack *elem1;
	t_stack *elem2;
	long long	tmp;

	elem1 = *b;
	elem2 = elem1->next;
	tmp = elem1->content;
	elem1->content = elem2->content;
	elem2->content = tmp;
	ft_putstr_fd ("sb\n", 1);
	return ;
}

//pa: Prend le premier élément
// de la pile b et le place en haut de la pile a
//, si b n'est pas vide.
void pa(t_stack **a, t_stack **b)
{
	if (!*b)
		return;
	t_stack *elem1;
	
	elem1 = *b;
	*b = (*b)->next;
	elem1->next = *a;
	*a = elem1;
	ft_putstr_fd ("pa\n", 1);
}

void pb(t_stack **a, t_stack **b)
{
	if (!*a)
		return;
	t_stack *elem1;
	
	elem1 = *a;
	*a = (*a)->next;
	elem1->next = *b;
	*b = elem1;
	ft_putstr_fd ("pb\n", 1);

}
