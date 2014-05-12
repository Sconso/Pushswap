/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 14:56:03 by sconso            #+#    #+#             */
/*   Updated: 2013/12/27 22:58:41 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

t_control		*ft_newlist(void)
{
	t_control	*tmp;

	tmp = (t_control *)malloc(sizeof(*tmp));
	if (!tmp)
		ft_exit("Error\n");
	tmp->sizea = 0;
	tmp->sizeb = 0;
	tmp->firsta = NULL;
	tmp->lasta = NULL;
	tmp->firstb = NULL;
	tmp->lastb = NULL;
	return (tmp);
}

t_l_a		*ft_pushlast(t_control *list, int nb)
{
	t_l_a	*node;

	node = (t_l_a *)malloc(sizeof(*node));
	if (list == NULL || !node)
		ft_exit("Error\n");
	node->nb = nb;
	if (list->lasta == NULL)
	{
		list->firsta = node;
		list->lasta = node;
		node->prev = node;
	}
	else
	{
		list->lasta->next = node;
		list->firsta->prev = node;
		node->prev = list->lasta;
		list->lasta = node;
	}
	node->next = list->firsta;
	list->sizea += 1;
	return (node);
}

void			ft_printlist(t_control *list, char way, char l, char *color)
{
	t_l_a		*tmp;
	int			i;

	if (way == 0)
		tmp = (!l ? list->firsta : list->firstb);
	else
		tmp = (!l ? list->lasta : list->lastb);
	i = (!l ? list->sizea : list->sizeb);
	if (!l)
		ft_putstr("Liste l_a = ( ");
	else
		ft_putstr("Liste l_b = ( ");
	while (i-- > 0)
	{
		ft_putstr(color);
		ft_putnbr(tmp->nb);
		ft_putstr("\033[0m");
		if (tmp->next)
			ft_putchar(' ');
		tmp = (way == 0 ? tmp->next : tmp->prev);
	}
	ft_putstr(")\n");
}

void		ft_printbothlists(t_control *list, char direction, char *color)
{
	ft_printlist(list, direction, 0, color);
	ft_printlist(list, direction, 1, color);
	ft_putchar('\n');
}
