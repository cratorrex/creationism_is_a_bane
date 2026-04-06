/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:43:17 by thtay             #+#    #+#             */
/*   Updated: 2026/04/03 15:43:19 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <math.h>

// //size_t	len = (dp + sf + (dp > 0) + (sf < 0);
// static char	*convert(int dp, int sf, double num)
// {
// 	char	*ret;
// 	int		i;

// 	i = 0;
// 	ret = malloc((dp + abs(sf) + (dp > 0)/*  + (sf < 0) */ + 1));
// 	printf("\n%d\n", (dp + abs(sf) + (dp > 0)/*  + (sf < 0) */ + 1));
// 	if (!ret)
// 		return (NULL);
// 	ft_bzero(ret, (dp + abs(sf) + (dp > 0)/*  + (sf < 0) */ + 1));
// 	if (sf < 0)
// 		ret[0] = '-';
// printf("sign:%d, data_start:%d, null_pos:%d\n", 
//        (sf < 0), 
//        abs(sf) + (dp>0) + (sf<0) + (sf < 0),
//        dp + abs(sf) + (dp>0) + (sf<0));
	   
// 	while (dp - i++)
// 		ret[abs(sf) + (dp > 0) + (sf < 0) + i - 1]
// 			= (int)(num * pow(10, i)) % 10 + '0';
// 	printf("\n%d \n", (abs(sf) + (dp > 0) + (sf < 0) + i));
// 	if (dp > 0)
// 		ret[(dp + abs(sf) + (dp > 0) + (sf < 0)) - i++] = '.';
// 	i = 0;
// 	while (abs(sf) - i++ > (sf < 0))
// 		ret[abs(sf) - i + (sf < 0)] = (int)(num / pow(10, i - 1)) % 10 + '0';
// 	return (ret);
// }

// #include "libft.h"

unsigned int	find_part(float src)
{
	unsigned int	n;
	int				i;

	i = 0;
	n = src * 1000000.0f;
	while (n % 10 == 0 && i++ < 6)
		n /= 10;
	return (n);
}

int	count_num(unsigned int src, char *dst)
{
	int				i;
	char			a;
	unsigned int	t;

	t = 1;
	i = 0;
	while (src / t > 9)
		t *= 10;
	while (t)
	{
		a = ((src / t) % 10) + '0';
		if (dst)
			dst[i] = a;
		i ++;
		t /= 10;
	}
	return (i);
}

//always print at least one digit for both whole and part
static char	*ft_ftoa(float src)
{
	unsigned int	whole;
	unsigned int	part;
	char			*ret;
	int				i;

	i = (src < 0);
	if (i)
		src = 0.0f - src;
	whole = (unsigned int) src;
	part = find_part(src - (float) whole);
	ret = malloc(count_num(whole, NULL) + count_num(part, NULL) + i + 2);
	if (!ret)
		return (0);
	if (i)
		ret[0] = '-';
	i += count_num(whole, &ret[i]);
	ret[i++] = '.';
	i += count_num(part, &ret[i]);
	ret[i] = '\0';
	return (ret);
}

int	handle_float(double num)
{
	char	*dec;
	size_t	len;

	dec = ft_ftoa(num);
	len = ft_strlen(dec);
	ft_putstr_fd(dec, 1);
	free(dec);
	return (len);
}
