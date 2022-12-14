/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:34:35 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/21 10:34:35 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LINKED_LIST_H
# define DOUBLY_LINKED_LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*previous;
	struct s_node	*next;
}	t_node;

t_node	*find_node_recursive(t_node *node, int value);
t_node	*find_node(t_node *tail, int value);
void	init(t_node **tail, t_node **head, int value);
void	insert_beginning(t_node **tail, int value);
void	deallocate(t_node **tail, t_node **head);
void	deallocate(t_node **tail, t_node **head);
void	insert_after(t_node *node, int value);
void	reverse(t_node **tail, t_node **head);
void	insert_end(t_node **head, int value);
void	iterate_back(t_node *head);
void	remove_node(t_node *node);
void	iterate(t_node *tail);

#endif