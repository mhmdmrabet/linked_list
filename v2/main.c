/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:39:16 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/12 09:39:16 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	iterate(t_node *root)
{
	t_node	*current;
	int		i;

	i = 0;
	current = root;
	while (current)
	{
		printf("[%d] : %d\n", i++, current->value);
		current = current->next;
	}
}

int	main(void)
{
	t_node	root;

	root.value = 15;
	root.next = malloc(sizeof(t_node));
	root.next->value = -2;
	root.next->next = malloc(sizeof(t_node));
	root.next->next->value = 22;
	root.next->next->next = NULL;
	iterate(&root);
	free(root.next->next);
	free(root.next);
	return (0);
}
