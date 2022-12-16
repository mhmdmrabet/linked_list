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

void	insert_end(t_node **root, int value)
{
	t_node	*new_node;
	t_node	*current;

	current = *root;
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(1);
	new_node->next = NULL;
	new_node->value = value;
	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

int	main(void)
{
	t_node	*root;

	root = malloc(sizeof(t_node));
	if (root == NULL)
		exit (1);
	root->next = NULL;
	root->value = 15;
	insert_end(&root, 22);
	insert_end(&root, 11);
	iterate(root);
	return (0);
}
