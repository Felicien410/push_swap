/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_fives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:02:34 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/22 20:37:30 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void two_params(t_stack **a)
{
    if (!(*a)->next->content)
        return;
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

void three_params(t_stack **a)
{
    t_stack *big;

    big = extrem (*a, 1);
    while ((*a)->content > (*a)->next->content)
        ra(a);
    if (big->prec->content < big->content)
        rra(a);
    if ((*a)->content > (*a)->next->content)
        sa(a);
    while ((*a)->content > (*a)->next->content)
        ra(a);
    while ((*a)->content > (*a)->next->content)
        ra(a);
    if ((*a)->next->content > (*a)->next->next->content) //pas trie return 0
    {
        rra(a);
        sa(a);
    }
}


void sort_four_elements(t_stack **a, t_stack **b)
{
    t_stack *big;

    big = extrem (*a, 1);
    while ((*a)->content != big->content)
        ra(a);
    pb(a, b);
    big = extrem (*a, 1);
    while ((*a)->content > (*a)->next->content)
        ra(a);
    if (big->prec->content < big->content)
        rra(a);
    if ((*a)->content > (*a)->next->content)
        sa(a);
    while ((*a)->content > (*a)->next->content)
        ra(a);
    while ((*a)->content > (*a)->next->content)
        ra(a);
    if ((*a)->next->content > (*a)->next->next->content) //pas trie return 0
    {
        rra(a);
        sa(a);
    }
    pa(a, b);
    ra(a);
}

void where_is_best(t_stack **a, t_stack	*first)
{
    if (where_is_start(*a, first->content) == 0)//en haut
        ra(a);
    else
        rra(a);
}



t_stack *find_second(t_stack *to_sort)
{
	if (to_sort == NULL || to_sort->next == NULL)
        return NULL;

	t_stack *smallest = NULL;
	t_stack *second_smallest = NULL;
	t_stack *current = to_sort;

	while (current != NULL) {
		if (smallest == NULL || current->content < smallest->content) {
			second_smallest = smallest;
			smallest = current;
		} else if (second_smallest == NULL || current->content < second_smallest->content) {
			if (current != smallest) {
				second_smallest = current;
			}
		}
		current = current->next;
	}

	return second_smallest;
}

void sort_five_elements(t_stack **a, t_stack **b)
{
	t_stack	*first;
    t_stack *second;
    
    first = extrem (*a, 0);
    second = find_second (*a);
    while ((*a)->content != first->content && (*a)->content != second->content)
        ra(a);
    pb(a, b);//push max to b
	first = extrem (*a, 0);  
    second = find_second (*a);
    while ((*a)->content != first->content && (*a)->content != second->content)
        ra(a);
    pb(a, b);
    while ((*a)->content > (*a)->next->content)
        ra(a);
    if ((*a)->content > (*a)->next->content)
        sa(a);
    while ((*a)->content > (*a)->next->content)
        ra(a);
    if ((*a)->next->content > (*a)->next->next->content) //pas trie return 0
    {
        rra(a);
        sa(a);
    }
    if ((*b)->content < (*b)->next->content)
		sa(b);
    pa(a, b);
    pa(a, b);
}
