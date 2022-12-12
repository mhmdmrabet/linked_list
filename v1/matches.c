/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matches.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:13:23 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/12 09:13:23 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	is_member(t_Node *node, int find_value)
{
	if (!node)
		return (0);
	else if (node->value == find_value)
		return (1);
	else
		return (is_member(node->next, find_value));
}

int	count_matches(t_Node *node, int find_value)
{
	if (!node)
		return (0);
	else if (node->value == find_value)
		return ((1 + count_matches(node->next, find_value)));
	else
		return (count_matches(node->next, find_value));
}

void	replace_matches(t_Node *node, int find_value, int replace_value)
{
	if (!node)
		return ;
	else if (node->value == find_value)
	{
		node->value = replace_value;
		replace_matches(node->next, find_value, replace_value);
	}
	else
		replace_matches(node->next, find_value, replace_value);
}
