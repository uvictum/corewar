/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:03:43 by vmorguno          #+#    #+#             */
/*   Updated: 2018/09/12 18:53:50 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char  *ft_uitoa_base(unsigned int value, int base, char c, int prfx)
{
  char  *s;
  size_t  n;
  int    i;

  n = value;
  i = prfx > 0 ? 3 : 1;
  while ((value /= base) > 0)
    i++;
  if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
    return (NULL);
  s[i] = '\0';
  while (i-- > 0 + (1 * prfx))
  {
    s[i] = (n % base < 10) ? n % base + '0' : n % base + c - 10;
    n /= base;
  }
  if (prfx)
  {
	  s[0] = '0';
	  s[1] = 'x';
  }
  return (s);
}
