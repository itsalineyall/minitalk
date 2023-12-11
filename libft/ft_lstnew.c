/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alinevieira <alinevieira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:16:33 by alvieira          #+#    #+#             */
/*   Updated: 2023/12/11 18:21:57 by alinevieira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// essa funcao cria um novo elemento da lista

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (newnode == NULL)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}
