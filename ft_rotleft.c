/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotleft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 16:53:25 by sconso            #+#    #+#             */
/*   Updated: 2013/12/27 22:53:16 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

char	*ft_ra(t_control **list)
{
	if (!list || !*list)
		ft_exit("Error\n");
	if ((*list)->firsta != (*list)->lasta)
	{
		(*list)->firsta = (*list)->firsta->next;
		(*list)->lasta = (*list)->lasta->next;
	}
	return ("ra");
}

char	*ft_rb(t_control **list)
{
	if (!list || !*list)
		ft_exit("Error\n");
	if ((*list)->firstb != (*list)->lastb)
	{
		(*list)->firstb = (*list)->firstb->next;
		(*list)->lastb = (*list)->lastb->next;
	}
	return ("rb");
}

char	*ft_rr(t_control **list)
{
	if (!list || !*list)
		ft_exit("Error\n");
	ft_ra(list);
	ft_rb(list);
	return ("rr");
}
