/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_straddchar.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/02 15:15:43 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/04/02 15:20:06 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddchar(char *str, char c, size_t off)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	i = 0;
	len = ft_strlen(str) + 1;
	tmp = ft_strnew(len);
	while (i < len)
	{
		if (i < off)
			tmp[i] = str[i];
		else if (i == off)
			tmp[i] = c;
		else
			tmp[i] = str[i - 1];
		i++;
	}
	ft_strdel(&str);
	return (tmp);
}
