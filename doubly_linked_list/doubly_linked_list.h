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


#endif