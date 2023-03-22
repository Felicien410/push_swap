/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:13:45 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/22 20:45:20 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void few_params(t_stack **a, t_stack **b)
{
	if (ft_lstlen (*a) == 2)
		two_params (a);
	if (ft_lstlen (*a) == 3)
		three_params (a);
	if (ft_lstlen (*a) == 4)
		sort_four_elements(a, b);
	if(ft_lstlen (*a) == 5)
		sort_five_elements(a, b);
	freeList(*a);
	exit(1);
}

int	main(int argc, char **argv)
{
	size_t	i;
	t_stack *a;
	t_stack *b;
	
	i = 1;
	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		while(argv[i])
		{
			if (ft_count_words(argv[i], ' ') == 1)
				add_to_list(&a, ft_atoi_ps(argv[i]));
			else if (ft_count_words(argv[i], ' ') > 1)
			{
				split_and_replace(argv[i], &a);
			}
			i++;
		}
		if (verif_sort (a) == 1)
		{
			freeList(a);
			exit(1);
		}
		if(ft_lstlen (a) <= 5)
			few_params(&a, &b);
		ft_insertion(&a, &b);
		// printf("liste a after \n\n");
		// ft_print_list(a);
		// printf("liste b after \n\n");
		// ft_print_list(b);
		// freeList(a);
	}
	return 0;
}
