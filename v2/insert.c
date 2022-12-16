/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:58:43 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/16 18:58:43 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	insert_end(t_node **root, int value)
{
	t_node	*new_node;
	t_node	*current;

	current = *root;
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(1);
	new_node->next = NULL;
	new_node->value = value;
	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

void	insert_beginning(t_node **root, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit (1);
	new_node->value = value;
	new_node->next = *root;
	*root = new_node;
}

void	insert_after(t_node *node, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(1);
	new_node->value = value;
	new_node->next = node->next;
	node->next = new_node;
}
