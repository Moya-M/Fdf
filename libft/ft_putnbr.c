/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:18:03 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:18:04 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long l;
	char c;

	l = (long)n;
	c = '0';
	if (l < 0)
	{
		write(1, "-", 1);
		l = -l;
	}
	if (l > 9)
	{
		ft_putnbr((int)(l / 10));
		c += l % 10;
		write(1, &c, 1);
	}
	else
	{
		c += l;
		write(1, &c, 1);
	}
}
