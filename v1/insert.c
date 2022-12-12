/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:06:18 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/12 09:06:18 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_Node	*insert_at_head(t_Node *head, int new_value)
{
	t_Node	*new_node;

	new_node = calloc(1, sizeof(t_Node));
	new_node->value = new_value;
	if (head)
		new_node->next = head;
	return (new_node);
}

t_Node	*insert_at_tail(t_Node *head, int new_value)
{
	t_Node	*new_node;
	t_Node	*current;

	current = head;
	new_node = calloc(1, sizeof(t_Node));
	new_node->value = new_value;
	new_node->next = NULL;
	if (head == NULL)
		return (new_node);
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
		return (head);
	}
}

t_Node	*append_list(t_Node *head1, t_Node *head2)
{
	t_Node	*current;

	current = head1;
	if (!head1)
		return (head2);
	while (current->next)
	{
		current = current->next;
	}
	current->next = head2;
	return (head1);
}