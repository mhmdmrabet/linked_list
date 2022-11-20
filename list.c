#include <stdio.h>

typedef	struct node {
	int	value;
	struct node	*next;
} Node;

void	print_list(Node *head);

int	main(void)
{
	Node	*list1_head;

	list1_head = NULL;
	print_list(&list1_head);
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
