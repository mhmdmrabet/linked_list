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

int	main(void)
{
	t_node	*tail;

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
	return (0);
}
