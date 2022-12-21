/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:50:05 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/21 12:50:05 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./doubly_linked_list.h"

void	iterate_back(t_node *head)
{
	t_node	*current;

	current = head;
	while (current)
	{
		printf("[-] %d\n", current->value);
		current = current->previous;
	}
}

void	iterate(t_node *tail)
{
	t_node	*current;
	int		i;

	current = tail;
	i = 0;
	while (current)
	{
		printf("[%d] %d\n", i++, current->value);
		current = current->next;
	}
}
