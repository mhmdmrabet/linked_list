#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int			value;
	struct node	*next;
}	t_Node;

void	print_list(t_Node *head);
t_Node	*insert_at_head(t_Node *head, int new_value);
t_Node	*insert_at_tail(t_Node *head, int new_value);
t_Node	*delete_at_head(t_Node *head);
t_Node	*delete_at_tail(t_Node *head);

int	main(void)
{
	t_Node	*list1_head;

	list1_head = NULL;
	list1_head = insert_at_head(list1_head, 7);
	list1_head = insert_at_head(list1_head, 4);
	list1_head = insert_at_head(list1_head, 2);
	list1_head = insert_at_tail(list1_head, 22);
	printf("BEFORE\n");
	print_list(list1_head);
	list1_head = delete_at_head(list1_head);
	list1_head = delete_at_tail(list1_head);
	printf("AFTER\n");
	print_list(list1_head);
	free(list1_head);
}

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
