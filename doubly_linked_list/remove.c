/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:34:57 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/21 15:34:57 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./doubly_linked_list.h"

void	remove_node(t_node *node)
{
	if (node->previous != NULL)
		node->previous->next = node->next;
	if (node->next != NULL)
		node->next->previous = node->previous;
	free(node);
}
