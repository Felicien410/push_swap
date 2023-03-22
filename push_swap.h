/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:14:13 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/22 20:44:21 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include"unistd.h"
#include"stdlib.h"
# include"libft/libft.h"

typedef struct	s_stack
{
    long long         content;
	struct		s_stack *next;
	struct		s_stack *prec;
}               t_stack;

//split
char			**ft_split_ps(char const *s, char c);
long long 		ft_count(char const *s, char c, long long  t);
long long 	ft_count_words(const char *str, char c);
long long 	ft_len_split(const char *s, char c);
void	*ft_freearray(char **s, long long  i);

//utils
long long 	ft_atoi_ps(const char *str);
void	ft_put_error (void);

//list
void add_to_list(t_stack **first, long long  value);
void	ft_print_list(t_stack *lst);
t_stack	*split_and_replace(char *str,t_stack **a);
void verif_double (t_stack *lst, long long  nb);
int	ft_lstlen(t_stack *lst);
int cmp(long long first, long long second);
int verif_sort (t_stack *to_sort);
void ft_insertion(t_stack **a, t_stack **b);
int	how_many_chunck(t_stack *to_sort);
void ft_sorting (t_stack **a, t_stack **b, long long chunk, int nb_chunks);
int verif_if_any_chunk(t_stack **a,long long chunk);
void three_params(t_stack **a);
int where_is_start(t_stack *b, long long to_find);
void put_on_top (t_stack *longuest, t_stack **b);
void other_side (t_stack **a, t_stack **b);
t_stack *next_extrem(t_stack *to_sort, int i, long long val);
void put_down (t_stack *longuest, t_stack **b);
void two_params(t_stack **a);
void act_if_value_on_top (long long tmp, t_stack **a, t_stack **b, int i);
t_stack *up_actualise (t_stack **b, t_stack *tmp);
void    verif_integers (long long value);
int where_the_next_nb_for_chunk (t_stack **a, long long chunk_total);
t_stack	*ft_lstlast_ps(t_stack *lst);
t_stack *down_actualise (t_stack **b, t_stack *tmp);
void sort_four_elements(t_stack **a, t_stack **b);
void sort_five_elements(t_stack **a, t_stack **b);
void where_is_best(t_stack **a, t_stack	*first);
void	freeList(t_stack *stack);
void verif_all(t_stack **first, long long value);
void	push_to_bigger_chunk(t_stack **a, t_stack **b, long long chunk_total);
t_stack *find_second(t_stack *to_sort);
long long help_atoi(const char *str, int i, long long result);

//operation
void	sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);
t_stack *extrem(t_stack *to_sort, int i);

#endif