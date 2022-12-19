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

void	deallocate(t_node **root)
{
	t_node	*curr;
	t_node	*tmp;

	curr = *root;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	*root = NULL;
}

int	main(void)
{
	t_node	*root;

	root = NULL;
	insert_sorted(&root, 1);
	insert_sorted(&root, 3);
	insert_sorted(&root, 6);
	reverse(&root);
	iterate(root);
	deallocate(&root);
	return (0);
}
