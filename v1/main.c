/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:08:34 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/12 09:08:34 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	print_list(t_Node *head)
{
	t_Node	*current;
	int		i;

	i = 0;
	current = head;
	while (current != NULL)
	{
		printf("t_Node %d : %d\n", i, current->value);
		current = current->next;
		i++;
	}
}

int	main(void)
{
	t_Node	*list1_head;

	list1_head = NULL;
	list1_head = insert_at_head(list1_head, 7);
	list1_head = insert_at_tail(list1_head, 11);
	list1_head = insert_at_tail(list1_head, 11);
	print_list(list1_head);
}
