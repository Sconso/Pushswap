/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotright.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 14:46:54 by sconso            #+#    #+#             */
/*   Updated: 2013/12/27 22:54:24 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

char	*ft_rra(t_control **list)
{
	if (!list || !*list)
		ft_exit("Error\n");
	if ((*list)->firsta != (*list)->lasta)
	{
		(*list)->firsta = (*list)->lasta;
		(*list)->lasta = (*list)->lasta->prev;
	}
	return ("rra");
}

char	*ft_rrb(t_control **list)
{
	if (!list || !*list)
		ft_exit("Error\n");
	if ((*list)->firstb != (*list)->lastb)
	{
		(*list)->firsta = (*list)->lasta;
		(*list)->lasta = (*list)->lasta->prev;
	}
	return ("rrb");
}

char	*ft_rrr(t_control **list)
{
	if (!list || !*list)
		ft_exit("Error\n");
	ft_rra(list);
	ft_rrb(list);
	return ("rrr");
}
