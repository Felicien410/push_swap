/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_other_side.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:07:09 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/22 20:37:12 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	act_if_value_on_top(long long tmp, t_stack **a, t_stack **b, int i)
{
	t_stack	*longuest;
	
	longuest = extrem (*b, 1);
	if (tmp == longuest->content)
		pa (a, b);
	else
	{
		pa (a, b);
		if (i == 1)
			put_down (longuest, b);
		else
			put_on_top (longuest, b);
		if (i == 1)
			rrb (b);
		pa (a, b);
		sa (a);
	}
}

t_stack	*up_actualise(t_stack **b, t_stack *tmp)
{
    rb (b);
    tmp = *b;
    return (tmp);
}

t_stack	*down_actualise(t_stack **b, t_stack *tmp)
{
    rrb (b);
    tmp = *b;
    return (tmp);
}
	
void	other_side(t_stack **a, t_stack **b)
{
	t_stack	*longuest;
	t_stack	*pre_longuest;
	t_stack	*tmp;

	tmp = *b;
	longuest = extrem (*b, 1);
	pre_longuest = next_extrem (*b, 1, longuest->content);
	while (tmp)
	{
		if (ft_lstlen (*b) == 1)
		{
			pa(a , b);
			return;
		}
		if (ft_lstlen (*b) == 2)
		{
			if ((*b)->content > (*b)->next->content)
			{
				pa(a, b);
				pa(a, b);
			}
			else
			{
				sb(b);
				pa(a, b);
				pa(a, b);
			}
			return;
		}
		tmp = *b;
		if(where_is_start (tmp, longuest->content) == 0)
		{
			while (tmp->content != longuest->content 
				&& tmp->content != pre_longuest->content)
				tmp = up_actualise (b, tmp);
			act_if_value_on_top (tmp->content, a, b, 0);
		}
		else //si en bas + proche
		{
			while (tmp->content != longuest->content 
				&& tmp->content != pre_longuest->content)
				tmp = down_actualise (b, tmp);
			act_if_value_on_top (tmp->content, a, b, 1);
		}
		longuest = extrem (*b, 1);
		pre_longuest = next_extrem (*b, 1, longuest->content);
	}
}