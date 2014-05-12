/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 01:29:32 by sconso            #+#    #+#             */
/*   Updated: 2013/12/27 23:15:16 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strrev(char *str)
{
	char	temp_tab[100000];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	i--;
	while (i >= 0)
	{
		temp_tab[j] = str[i];
		i--;
		j++;
	}
	temp_tab[j] = '\0';
	str = temp_tab;
	return (str);
}
