/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: valyssa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:20:13 by valyssa-          #+#    #+#             */
/*   Updated: 2024/10/29 14:28:07 by valyssa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

int		count_w(const char *s, char c);
void	allocate(char **sub, char const *s, char c);
void	free_s(char **s);

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	words = count_w(s, c);
	str = (char **)malloc(sizeof(char *) * (words + 1));
	if (str == NULL)
		return (NULL);
	allocate(str, s, c);
	while (i < words)
	{
		if (str[i] == NULL)
		{
			free_s(str);
			return (NULL);
		}
		i++;
	}
	str[i] = NULL;
	return (str);
}

int	count_w(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
		{
			i++;
		}
		if (s[i] != '\0' && s[i] != c)
		{
			j++;
		}
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
		}
	}
	return (j);
}

void	allocate(char **sub, char const *s, char c)
{
	char		**sub1;
	char const	*str;

	str = s;
	sub1 = sub;
	while (*str != '\0')
	{
		while (*s == c)
			s++;
		str = s;
		while (*str && *str != c)
		{
			str++;
		}
		if (*str == c || str > s)
		{
			*sub1 = ft_substr(s, 0, str - s);
			if (*sub1 == NULL)
				return ;
			s = str;
			sub1++;
		}
	}
	*sub1 = NULL;
}

void	free_s(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
}
/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
	{
		len = len_s - start;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (len > i)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*dest;

	len = 0;
	i = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	dest = (char *) malloc (sizeof(char) * len + 1);
	if (dest == NULL)
	{
		return (NULL);
	}
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	main() {
    char **res;
    char *str = "  Olá, meu   nome é Victoria";
    char d = ' ';

    res = ft_split(str, d);

    while (*res != NULL)
	{
        printf("%s\n", *res);
        res++;
    }
    free(*res);

    return 0;
}*/