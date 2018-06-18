/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrmchar.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/02 15:20:29 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 15:21:00 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrmchar(char *str, size_t off, int rev)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	i = 0;
	len = ft_strlen(str) - 1;
	tmp = ft_strnew(len);
	while (i < len)
	{
		if (i < off - rev)
			tmp[i] = str[i];
		else
			tmp[i] = str[i + 1];
		i++;
	}
	ft_strdel(&str);
	return (tmp);
}
