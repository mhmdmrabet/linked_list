/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:55:16 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/19 14:55:16 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linked_list.h"

void	remove_element(t_node **root, int value)
{
	t_node	*current;
	t_node	*to_remove;

	current = *root;
	if (*root == NULL)
		return ;
	if ((*root)->value == value)
	{
		to_remove = *root;
		*root = (*root)->next;
		free(to_remove);
		return ;
	}
	while (current->next != NULL)
	{
		if (current->next->value == value)
		{
			to_remove = current->next;
			current->next = current->next->next;
			free(to_remove);
			return ;
		}
		current = current->next;
	}
}
