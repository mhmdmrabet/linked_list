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

int	main(void)
{
	t_node	*tail;
	t_node	*head;

	tail = malloc(sizeof(t_node));
	if (tail == NULL)
		return (1);
	tail->value = 1;
	tail->previous = NULL;
	tail->next = malloc(sizeof(t_node));
	if (tail->next == NULL)
		return (2);
	tail->next->value = 3;
	tail->next->previous = tail;
	tail->next->next = NULL;
	head = tail->next;
	iterate(tail);
	iterate_back(head);
	deallocate(&tail, &head);
	return (0);
}
