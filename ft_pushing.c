/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 16:32:34 by sconso            #+#    #+#             */
/*   Updated: 2013/12/27 22:51:58 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

char	*ft_pa(t_control **list)
{
	if (list == NULL || *list == NULL || (*list)->firstb == NULL)
		ft_exit("Error/n");
	(*list)->firsta = (*list)->firstb;
	(*list)->firstb = (*list)->firstb->next;
	(*list)->firstb->prev = (*list)->lastb;
	(*list)->lastb->next = (*list)->firstb;
	if ((*list)->sizea == 0)
	{
		(*list)->lasta = (*list)->firsta;
		(*list)->firsta->next = (*list)->lasta;
		(*list)->firsta->prev = (*list)->lasta;
	}
	(*list)->firsta->next = (*list)->lasta->next;
	(*list)->firsta->next->prev = (*list)->firsta;
	(*list)->firsta->prev = (*list)->lasta;
	(*list)->lasta->next = (*list)->firsta;
	(*list)->sizea += 1;
	(*list)->sizeb -= 1;
	return ("pa");
}

char	*ft_pb(t_control **list)
{
	if (list == NULL || *list == NULL || (*list)->firsta == NULL)
		ft_exit("Error/n");
	(*list)->firstb = (*list)->firsta;
	(*list)->firsta = (*list)->firsta->next;
	(*list)->firsta->prev = (*list)->lasta;
	(*list)->lasta->next = (*list)->firsta;
	if ((*list)->sizeb == 0)
	{
		(*list)->lastb = (*list)->firstb;
		(*list)->firstb->next = (*list)->lastb;
		(*list)->firstb->prev = (*list)->lastb;
	}
	(*list)->firstb->next = (*list)->lastb->next;
	(*list)->firstb->next->prev = (*list)->firstb;
	(*list)->firstb->prev = (*list)->lastb;
	(*list)->lastb->next = (*list)->firstb;
	(*list)->sizeb += 1;
	(*list)->sizea -= 1;
	return ("pb");
}
