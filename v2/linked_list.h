/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:33:30 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/12 09:33:30 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

void	insert_beginning(t_node **root, int value);
void	insert_sorted(t_node **root, int value);
void	insert_after(t_node *node, int value);
void	insert_end(t_node **root, int value);
void	deallocate(t_node **root);
void	iterate(t_node *root);

#endif