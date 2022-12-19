/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:10:50 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/16 19:10:50 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	insert_sorted(t_node **root, int value)
{
	t_node	*current;

	current = *root;
	if (*root == NULL || (*root)->value >= value)
	{
		insert_beginning(root, value);
		return ;
	}
	while (current->next != NULL)
	{
		if (current->next->value >= value)
			break ;
		current = current->next;
	}
	insert_after(current, value);
}
