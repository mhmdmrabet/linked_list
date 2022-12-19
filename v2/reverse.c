/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:50:17 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/19 19:50:17 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linked_list.h"

void	reverse(t_node **root)
{
	t_node	*previous;
	t_node	*current;
	t_node	*next;

	previous = NULL;
	current = *root;
	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*root = previous;
}

