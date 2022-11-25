#include "list.h"

t_Node	*insert_at_head(t_Node *head, int new_value)
{
	t_Node	*new_node;

	new_node = calloc(1, sizeof(t_Node));
	new_node->value = new_value;
	if (head)
		new_node->next = head;
	return (new_node);
}

t_Node	*insert_at_tail(t_Node *head, int new_value)
{
	t_Node	*new_node;
	t_Node	*current;

	current = head;
	new_node = calloc(1, sizeof(t_Node));
	new_node->value = new_value;
	new_node->next = NULL;
	if (head == NULL)
		return (new_node);
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
		return (head);
	}
}

t_Node	*delete_at_head(t_Node *head)
{
	t_Node	*to_return;

	if (!head)
		return (NULL);
	to_return = head->next;
	free(head);
	return (to_return);
}

t_Node	*delete_at_tail(t_Node *head)
{
	t_Node	*current;
	t_Node	*previous;

	current = head;
	previous = NULL;
	if (!head)
		return (NULL);
	else if (!head->next)
	{
		free(head);
		return (NULL);
	}
	else
	{
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
		}
		previous->next = NULL;
		free(current);
		return (head);
	}
}

t_Node	*delete_first_match(t_Node *head, int delete_value, int *was_deleted)
{
	t_Node	*previous;
	t_Node	*current;
	t_Node	*tmp;

	if (!head)
	{
		*was_deleted = 0;
		return (NULL);
	}
	if (head->value == delete_value)
	{
		tmp = head->next;
		free(head);
		*was_deleted = 1;
		return (tmp);
	}
	current = head->next;
	previous = head;
	while (current)
	{
		if (current->value == delete_value)
		{
			previous->next = current->next;
			free(current);
			*was_deleted = 1;
			return (head);
		}
		previous = current;
		current = current->next;
	}
	*was_deleted = 0;
	return (head);
}

t_Node	*delete_all_matches(t_Node *head, int delete_value, int *num_deleted)
{
	t_Node	*current;
	int		deleted;

	*num_deleted = 0;
	current = head;
	deleted = 1;
	while (deleted)
	{
		deleted = 0;
		current = delete_first_match(current, delete_value, &deleted);
		if (deleted)
			*num_deleted = *num_deleted + 1;
	}
	return (current);
}

t_Node	*efficient_delete_match(t_Node *head, int delete_value, int *num_del)

{
	t_Node	*current;
	t_Node	*new_head;
	t_Node	*tmp;

	current = head;
	*num_del = 0;
	if (!head)
		return (NULL);
	while (current->value == delete_value)
	{
		tmp = current;
		current = current->next;
		free(tmp);
		*num_del= *num_del + 1;
		if (!current)
			return (NULL);
	}
	new_head = current;
	while (current->next)
	{
		if (current->next->value == delete_value)
		{
			tmp = current->next;
			current->next = current->next->next;
			free(tmp);
			*num_del = *num_del + 1;
		}
		else
			current = current->next;
	}
	return (new_head);
}

t_Node	*append_list(t_Node *head1, t_Node *head2)
{
	t_Node	*current;

	current = head1;
	if (!head1)
		return (head2);
	while (current->next)
	{
		current = current->next;
	}
	current->next = head2;
	return (head1);
}

t_Node	*reverse_list(t_Node *head)
{
	t_Node	*next_node;
	t_Node	*current;
	t_Node	*tmp;

	if (!head)
		return (NULL);
	if (!head->next)
		return (head);
	current = head;
	next_node = head->next;
	current->next = NULL;
	while (next_node)
	{
		tmp = next_node->next;
		next_node->next = current;
		current = next_node;
		next_node = tmp;
	}
	return (current);
}

t_Node	*reverse_list_iterative(t_Node *head)
{
	t_Node	*current;
	t_Node	*previous;
	t_Node	*next;

	current = head;
	previous = NULL;
	next = NULL;
	// NULL			->	a		->	b 		-> c
	// previous			current		next	
	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	return (previous);
}


int	recursive_length(t_Node *node)
{
	if (!node)
		return (0);
	return (1 + recursive_length(node->next));
}

int	length(t_Node *head)
{
	t_Node	*current;
	int		i;

	current = head;
	i = 0;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

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
