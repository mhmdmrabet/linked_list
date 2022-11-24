#ifndef LIST_H
# define LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_node{
	int				value;
	struct s_node	*next;
}	t_Node;

t_Node	*efficient_delete_match(t_Node *head, int delete_value, int *num_deleted);
t_Node	*delete_all_matches(t_Node *head, int delete_value, int *num_deleted);
t_Node	*delete_first_match(t_Node *head, int delete_value, int *was_deleted);
t_Node	*insert_at_head(t_Node *head, int new_value);
t_Node	*insert_at_tail(t_Node *head, int new_value);
t_Node	*delete_at_head(t_Node *head);
t_Node	*delete_at_tail(t_Node *head);
void	replace_matches(t_Node *node, int find_value, int replace_value);
void	print_list(t_Node *head);
int		recursive_length(t_Node *node);
int		is_member(t_Node *node, int find_value);
int		count_matches(t_Node *node, int find_value);
int		length(t_Node *head);

#endif