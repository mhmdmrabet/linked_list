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

int	main(void)
{
	t_node	*tail;
	t_node	*head;

	tail = NULL;
	head = NULL;
	init(&tail, &head, 7);
	insert_end(&head, 22);
	insert_end(&head, 33);
	insert_end(&head, 11);
	iterate(tail);
	reverse(&tail, &head);
	printf("\t\tREVERSE\n");
	iterate(tail);
	deallocate(&tail, &head);
	return (0);
}

void	reverse(t_node **tail, t_node **head)
{
	t_node	*current;
	t_node	*next;
	t_node	*aux;

	current = *tail;
	while (current)
	{
		next = current->next;
		current->next = current->previous;
		current->previous = next;
		current = next;
	}
	aux = *tail;
	*tail = *head;
	*head = aux;
}

t_node	*find_node(t_node *tail, int value)
{
	t_node	*current;

	current = tail;
	while (current)
	{
		if (current->value == value)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_node	*find_node_recursive(t_node *node, int value)
{
	if (node == NULL)
		return (NULL);
	if (node->value == value)
		return (node);
	return (find_node_recursive(node->next, value));
}

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