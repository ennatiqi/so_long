#include "animation.h"

static int	lenght(int n)
{
	int				i;
	long long int	tmp;

	tmp = (long long int) n;
	i = 0;
	if (tmp <= 0)
	{
		i = 1;
		tmp *= -1;
	}
	while (tmp != 0)
	{
		i++;
		tmp = tmp / 10;
	}
	return (i);
}

static char	*put(char *resulta, int n)
{
	int				i;
	long long int	nb;

	nb = n;
	i = lenght(nb);
	resulta[i--] = '\0';
	if (nb == 0)
	{
		resulta[0] = 48;
		return (resulta);
	}
	if (nb < 0)
	{
		resulta[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		resulta[i] = 48 + (nb % 10);
		nb /= 10;
		i--;
	}
	return (resulta);
}

char	*ft_itoa(int n)
{
	char	*resulta;
	int		len;

	len = lenght(n);
	resulta = (char *)malloc(len + 1);
	if (!resulta)
		return (0);
	resulta = put(resulta, n);
	return (resulta);
}

char	*ft_strjoin_walk(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*resulta;

	i = 0;
	if (!s1 || !s2)
		return (0);
	resulta = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof(char));
	if (!resulta)
		return (0);
	while (i < ft_strlen(s1))
	{
		resulta[i] = ((char *)s1)[i];
		i++;
	}
	j = 0;
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		resulta[i] = s2[j];
		i++;
		j++;
	}
	resulta[i] = '\0';
	free(s2);
	return (resulta);
}
