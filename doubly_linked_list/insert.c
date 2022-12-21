/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:06:53 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/21 13:06:53 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./doubly_linked_list.h"

void	insert_beginning(t_node **tail, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->value = value;
	new_node->previous = NULL;
	new_node->next = *tail;
	*tail = new_node;
}

void	insert_end(t_node **head, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	new_node->previous = *head;
	(*head)->next = new_node;
	*head = new_node;
}

void	insert_after(t_node *node, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->value = value;
	new_node->next = node->next;
	new_node->previous = node;
	if (node->next != NULL)
		node->next->previous = new_node;
	node->next = new_node;
}
