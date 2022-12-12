/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:10:23 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/12 09:10:23 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	recursive_length(t_Node *node)
{
	if (!node)
		return (0);
	return (1 + recursive_length(node->next));
}

int	length(t_Node *head)
{
	t_Node	*current;
	int		i;

	current = head;
	i = 0;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

