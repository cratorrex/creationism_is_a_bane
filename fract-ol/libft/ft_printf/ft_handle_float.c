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
#include <math.h>

//size_t	len = (dp + sf + (dp > 0) + (sf < 0);
static char	*convert(int dp, int sf, double num)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc((dp + abs(sf) + (dp > 0)/*  + (sf < 0) */ + 1));
	printf("\n%d\n", (dp + abs(sf) + (dp > 0)/*  + (sf < 0) */ + 1));
	if (!ret)
		return (NULL);
	ft_bzero(ret, (dp + abs(sf) + (dp > 0)/*  + (sf < 0) */ + 1));
	if (sf < 0)
		ret[0] = '-';
printf("sign:%d, data_start:%d, null_pos:%d\n", 
       (sf < 0), 
       abs(sf) + (dp>0) + (sf<0) + (sf < 0),
       dp + abs(sf) + (dp>0) + (sf<0));
	   
	while (dp - i++)
		ret[abs(sf) + (dp > 0) + (sf < 0) + i - 1]
			= (int)(num * pow(10, i)) % 10 + '0';
	printf("\n%d \n", (abs(sf) + (dp > 0) + (sf < 0) + i));
	if (dp > 0)
		ret[(dp + abs(sf) + (dp > 0) + (sf < 0)) - i++] = '.';
	i = 0;
	while (abs(sf) - i++ > (sf < 0))
		ret[abs(sf) - i + (sf < 0)] = (int)(num / pow(10, i - 1)) % 10 + '0';
	return (ret);
}

static void	length(double num, int *dp, int *sf)
{
	double	deci;

	deci = fmod(num, 1);
	num = floor(num);
	while (num / 10 > 0.9)
	{
		num = num / 10;
		*sf = *sf + 1;
	}
	while (((int)(deci * 10)) % 10 > 0 && *dp < 10)
	{
		printf("%d ", (int)(num * pow(10, *dp + 1)) % 10);
		deci = deci * 10;
		*dp = *dp + 1;
	}
}

//dp decimal places
//sf significant figures (signed for negative)
static char	*ft_dtoa(double num)
{
	int	dp;
	int	sf;

	dp = 0;
	sf = 1;
	if (num < 0)
	{
		sf++;
		num *= -1;
		length(num, &dp, &sf);
		sf *= -1;
		return (convert(dp, sf, num));
	}
	length(num, &dp, &sf);
	return (convert(dp, sf, num));
}

int	handle_float(double num)
{
	char	*dec;
	size_t	len;

	dec = ft_dtoa(num);
	len = ft_strlen(dec);
	printf("\n\n%s\n", dec);
	ft_putstr_fd(dec, 1);
	free(dec);
	return (len);
}
