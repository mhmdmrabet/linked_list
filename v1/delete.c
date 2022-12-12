/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:07:16 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/12 09:07:16 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_Node	*delete_at_head(t_Node *head)
{
	t_Node	*to_return;

	if (!head)
		return (NULL);
	to_return = head->next;
	free(head);
	return (to_return);
}

t_Node	*delete_at_tail(t_Node *head)
{
	t_Node	*current;
	t_Node	*previous;

	current = head;
	previous = NULL;
	if (!head)
		return (NULL);
	else if (!head->next)
	{
		free(head);
		return (NULL);
	}
	else
	{
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
		}
		previous->next = NULL;
		free(current);
		return (head);
	}
}

t_Node	*delete_first_match(t_Node *head, int delete_value, int *was_deleted)
{
	t_Node	*previous;
	t_Node	*current;
	t_Node	*tmp;

	if (!head)
	{
		*was_deleted = 0;
		return (NULL);
	}
	if (head->value == delete_value)
	{
		tmp = head->next;
		free(head);
		*was_deleted = 1;
		return (tmp);
	}
	current = head->next;
	previous = head;
	while (current)
	{
		if (current->value == delete_value)
		{
			previous->next = current->next;
			free(current);
			*was_deleted = 1;
			return (head);
		}
		previous = current;
		current = current->next;
	}
	*was_deleted = 0;
	return (head);
}

t_Node	*delete_all_matches(t_Node *head, int delete_value, int *num_deleted)
{
	t_Node	*current;
	int		deleted;

	*num_deleted = 0;
	current = head;
	deleted = 1;
	while (deleted)
	{
		deleted = 0;
		current = delete_first_match(current, delete_value, &deleted);
		if (deleted)
			*num_deleted = *num_deleted + 1;
	}
	return (current);
}

t_Node	*efficient_delete_match(t_Node *head, int delete_value, int *num_del)
{
	t_Node	*current;
	t_Node	*new_head;
	t_Node	*tmp;

	current = head;
	*num_del = 0;
	if (!head)
		return (NULL);
	while (current->value == delete_value)
	{
		tmp = current;
		current = current->next;
		free(tmp);
		*num_del = *num_del + 1;
		if (!current)
			return (NULL);
	}
	new_head = current;
	while (current->next)
	{
		if (current->next->value == delete_value)
		{
			tmp = current->next;
			current->next = current->next->next;
			free(tmp);
			*num_del = *num_del + 1;
		}
		else
			current = current->next;
	}
	return (new_head);
}

