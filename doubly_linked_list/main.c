/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:37:40 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/21 10:37:40 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./doubly_linked_list.h"

void	deallocate(t_node **tail, t_node **head)
{
	t_node	*current;

	if (*tail == NULL)
		return ;
	current = *tail;
	while (current->next)
	{
		current = current->next;
		free(current->previous);
	}
	free(current);
	*tail = NULL;
	*head = NULL;
}

void	init(t_node **tail, t_node **head, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->value = value;
	new_node->previous = NULL;
	new_node->next = NULL;
	*tail = new_node;
	*head = new_node;
}

int	main(void)
{
	t_node	*tail;
	t_node	*head;

	tail = NULL;
	head = NULL;
	init(&tail, &head, 7);
	insert_beginning(&tail, 3);
	insert_beginning(&tail, 1);
	insert_end(&head, 5);
	iterate_back(head);
	deallocate(&tail, &head);
	return (0);
}
