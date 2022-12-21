/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:11:14 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/21 10:11:14 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linked_list.h"

int	count(t_node *root)
{
	t_node	*current;
	int		c;

	current = root;
	c = 0;
	while (current)
	{
		c++;
		current = current->next;
	}
	return (c);
}

int	count_recursive(t_node *node)
{
	if (node == NULL)
		return (0);
	return (1 + count_recursive(node->next));
}
