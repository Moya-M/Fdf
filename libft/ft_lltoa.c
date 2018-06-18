/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lltoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 21:06:57 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 21:07:09 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa(off_t l)
{
	char	*str;
	int		i;
	int		neg;

	neg = 0;
	i = ft_countdigit(l);
	if (l < 0)
	{
		neg = 1;
		l *= -1;
	}
	i += neg;
	if (!(str = ft_strnew(i--)))
		return (NULL);
	if (l == 0)
		str[0] = '0';
	while (l > 0)
	{
		str[i--] = (l % 10) + '0';
		l /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
