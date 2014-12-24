/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 14:25:43 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/27 10:28:43 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "sort_ls.h"
#include <string.h>

static int		ft_cmp(t_list *a, t_list *b, int opt)
{
	if (opt & TIME && !(opt & REVERSE))
		return (F_TIME(a->stats.st_birthtime, b->stats.st_birthtime));
	else if (opt & TIME && opt & REVERSE)
		return (F_RTIME(a->stats.st_birthtime, b->stats.st_birthtime));
	if (opt & REVERSE)
		return (F_RASCII(a, b));
	return (F_ASCII(a, b));
}

static t_list	*ft_listcat(t_list *a, t_list *b, int opt)
{
	t_list	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	if (b == NULL)
		return (a);
	if (ft_cmp(a, b, opt))
	{
		result = a;
		result->next = ft_listcat(a->next, b, opt);
	}
	else
	{
		result = b;
		result->next = ft_listcat(a, b->next, opt);
	}
	return (result);
}

static void		ft_split_fb(t_list *src, t_list **front, t_list **back)
{
	t_list	*one;
	t_list	*two;

	if (src == NULL || src->next == NULL)
	{
		*front = src;
		*back = src;
	}
	else
	{
		two = src;
		one = src->next;
		while (one != NULL)
		{
			one = one->next;
			if (one != NULL)
			{
				two = two->next;
				one = one->next;
			}
		}
		*front = src;
		*back = two->next;
		two->next = NULL;
	}
}

void			ft_merge(t_list **first, int opt)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	if (*first == NULL || (*first)->next == NULL)
		return ;
	head = *first;
	ft_split_fb(head, &a, &b);
	ft_merge(&a, opt);
	ft_merge(&b, opt);
	*first = ft_listcat(a, b, opt);
}
