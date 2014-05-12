/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swaping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 16:46:01 by sconso            #+#    #+#             */
/*   Updated: 2013/12/27 22:59:13 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

char	*ft_sa(t_control **list)
{
	t_l_a	*tmp;

	if (!list || !*list)
		ft_exit("Error\n");
	if ((*list)->firsta != (*list)->lasta)
	{
		tmp = (*list)->firsta;
		(*list)->firsta = (*list)->firsta->next;
		(*list)->firsta->next->prev = tmp;
		tmp->next = (*list)->firsta->next;
		tmp->prev = (*list)->firsta;
		(*list)->firsta->next = tmp;
		(*list)->firsta->prev = (*list)->lasta;
		(*list)->lasta->next = (*list)->firsta;
	}
	return ("sa");
}

char	*ft_sb(t_control **list)
{
	t_l_a	*tmp;

	if (!list || !*list)
		ft_exit("Error\n");
	if ((*list)->firstb != (*list)->lastb)
	{
		tmp = (*list)->firstb;
		(*list)->firstb = (*list)->firstb->next;
		(*list)->firstb->next->prev = tmp;
		tmp->next = (*list)->firstb->next;
		tmp->prev = (*list)->firstb;
		(*list)->firstb->next = tmp;
		(*list)->firstb->prev = (*list)->lastb;
		(*list)->lastb->next = (*list)->firstb;
	}
	return ("sb");
}

char	*ft_ss(t_control **list)
{
	if (!list || !*list)
		ft_exit("Error\n");
	ft_sa(list);
	ft_sb(list);
	return ("ss");
}
