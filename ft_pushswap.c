/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 16:15:29 by sconso            #+#    #+#             */
/*   Updated: 2013/12/29 21:40:46 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int		ft_sorted(t_control *list)
{
	t_l_a	*tmp;
	int		i;

	tmp = list->firsta->next;
	i = list->sizea - 1;
	while (i-- > 0)
	{
		if (tmp->nb < tmp->prev->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		ft_sort_test(t_control **list, char type)
{
	int		i;
	int		j;

	j = 0;
	if (!list || !(*list) || (*list)->sizea < 2)
		return (0);
	while (!(i = ft_sorted(*list)) || (*list)->sizeb != 0)
	{
		if ((*list)->firsta->nb > (*list)->lasta->nb && type == 0)
			ft_ra(list);
		else if ((*list)->lasta->nb < (*list)->firsta->nb)
			ft_rra(list);
		else if ((*list)->firsta->nb > (*list)->firsta->next->nb)
			ft_sa(list);
		else if ((*list)->sizea > 2 && i == 0)
			ft_pb(list);
		else
			ft_pa(list);
		++j;
	}
	return (j);
}

void	ft_print_sort(t_control **list, char type, int *options)
{
	int		i;

	i = ft_sorted(*list);
	if (!list || !(*list) || (*list)->sizea < 2)
		return ;
	while (!i || (*list)->sizeb != 0)
	{
		if (options[1])
			ft_printbothlists(*list, 0, NONE);
		if ((*list)->firsta->nb > (*list)->lasta->nb && type == 0)
			ft_putstr(ft_ra(list));
		else if ((*list)->lasta->nb < (*list)->firsta->nb)
			ft_putstr(ft_rra(list));
		else if ((*list)->firsta->nb > (*list)->firsta->next->nb)
			ft_putstr(ft_sa(list));
		else if ((*list)->sizea > 2 && i == 0)
			ft_putstr(ft_pb(list));
		else
			ft_putstr(ft_pa(list));
		if ((i = ft_sorted(*list)) == 0 || (*list)->sizeb > 0)
			ft_putchar(' ');
		else
			ft_putchar('\n');
	}
}

int		*ft_parse(int *options, int *ac, char ***av)
{
	options = (int *)malloc(2 * sizeof(int));
	options[0] = 0;
	options[1] = 0;
	while (--(*ac) && (*++*av)[0] == '-')
	{
		while (*++(**av))
		{
			if (***av != 'c' && ***av != 'v')
			{
				ft_putstr("usage: ./push_swap [-cv] [numbers]\n");
				exit(0);
			}
			options[0] = (***av == 'c' ? 1 : options[0]);
			options[1] = (***av == 'v' ? 1 : options[1]);
		}
	}
	return (options);
}

int		main(int ac, char **av)
{
	t_control			*list;
	t_control			*clone1;
	t_control			*clone2;
	int					*options;

	list = ft_newlist();
	clone1 = ft_newlist();
	clone2 = ft_newlist();
	options = 0;
	options = ft_parse(options, &ac, &av);
	if (ac == 0)
		ft_exit("Error\n");
	while (ac-- > 0)
	{
		ft_pushlast(clone1, ft_atoi(*av));
		ft_pushlast(clone2, ft_atoi(*av));
		ft_pushlast(list, ft_atoi(*av));
		av++;
	}
	if (ft_sort_test(&clone1, 0) < ft_sort_test(&clone2, 1))
		ft_print_sort(&list, 0, options);
	else
		ft_print_sort(&list, 1, options);
	if (options[0])
		ft_printlist(list, 0, 0, RED);
	return (0);
}
