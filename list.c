#include <stdio.h>
#include <stdlib.h>

typedef	struct node {
	int	value;
	struct node	*next;
} Node;

void	print_list(Node *head);
Node	*insert_at_head(Node *head, int new_value);
Node	*insert_at_tail(Node *head, int new_value);

int	main(void)
{
	Node	*list1_head;

	list1_head = NULL;
	list1_head = insert_at_head(list1_head, 7);
	list1_head = insert_at_head(list1_head, 4);
	list1_head = insert_at_head(list1_head, 2);
	list1_head = insert_at_tail(list1_head, 22);
	print_list(list1_head);
	free(list1_head);
}

Node	*insert_at_head(Node *head, int new_value)
{
	Node	*new_node;

	new_node = calloc(1, sizeof(Node));
	new_node->value = new_value;
	if (head)
		new_node->next = head;
	return (new_node);
}

Node	*insert_at_tail(Node *head, int new_value)
{
	Node	*new_node;
	Node	*current;

	current = head;
	new_node = calloc(1, sizeof(Node));
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

void	print_list(Node *head)
{
	Node	*current;
	int		i;

	i = 0;
	current = head;
	while (current != NULL)
	{
		printf("Node %d : %d\n", i, current->value);
		current = current->next;
		i++;
	}
}
