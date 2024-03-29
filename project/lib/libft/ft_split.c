/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 08:23:09 by jkeum             #+#    #+#             */
/*   Updated: 2020/10/20 21:42:49 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cnt_words(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			cnt++;
		}
		else
			i++;
	}
	return (cnt);
}

static char		*get_arr(char const *s, char c, char *res, size_t idx)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (s[idx + len] != c && s[idx + len] != '\0')
		len++;
	if (!(res = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[idx + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static	void	*free_split(char **res, size_t res_idx)
{
	while (res_idx)
	{
		res_idx--;
		free(res[res_idx]);
	}
	free(res);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	res_idx;
	char	**res;

	if (!s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (cnt_words(s, c) + 1))))
		return (NULL);
	i = 0;
	res_idx = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		if (!(res[res_idx] = get_arr(s, c, res[res_idx], i)))
			return (free_split(res, res_idx));
		res_idx++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	res[res_idx] = NULL;
	return (res);
}
