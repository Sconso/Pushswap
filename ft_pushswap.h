/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 16:15:56 by sconso            #+#    #+#             */
/*   Updated: 2013/12/27 22:58:59 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# define RED ("\033[31m")
# define NONE ("\033[0m")

#include <libft.h>

typedef struct		s_l_a
{
	int				nb;
	struct s_l_a	*next;
	struct s_l_a	*prev;
}					t_l_a;

typedef struct		s_control
{
	t_l_a			*firsta;
	t_l_a			*lasta;
	t_l_a			*firstb;
	t_l_a			*lastb;
	int				sizea;
	int				sizeb;
}					t_control;

char		*ft_sa(t_control **list);
char		*ft_sb(t_control **list);
char		*ft_ss(t_control **list);
char		*ft_pa(t_control **list);
char		*ft_pb(t_control **list);
char		*ft_ra(t_control **list);
char		*ft_rb(t_control **list);
char		*ft_rr(t_control **list);
char		*ft_rra(t_control **list);
char		*ft_rrb(t_control **list);
char		*ft_rrr(t_control **list);
t_control	*ft_newlist(void);
t_l_a		*ft_pushlast(t_control *list, int nb);
void		ft_printlist(t_control *list, char way, char l, char *color);
void		ft_printbothlists(t_control *list, char direction, char *color);
void		ft_exit(char *error);
#endif /* FT_PUSHSWAP_H */
