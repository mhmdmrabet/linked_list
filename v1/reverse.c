/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:11:58 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/12 09:11:58 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_Node	*reverse_list(t_Node *head)
{
	t_Node	*next_node;
	t_Node	*current;
	t_Node	*tmp;

	if (!head)
		return (NULL);
	if (!head->next)
		return (head);
	current = head;
	next_node = head->next;
	current->next = NULL;
	while (next_node)
	{
		tmp = next_node->next;
		next_node->next = current;
		current = next_node;
		next_node = tmp;
	}
	return (current);
}

t_Node	*reverse_list_iterative(t_Node *head)
{
	t_Node	*current;
	t_Node	*previous;
	t_Node	*next;

	current = head;
	previous = NULL;
	next = NULL;
	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	return (previous);
}
