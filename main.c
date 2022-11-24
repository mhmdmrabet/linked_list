#include "list.h"

int	main(void)
{
	t_Node	*list1_head;
	t_Node	*list2_head;

	list1_head = NULL;
	list1_head = insert_at_head(list1_head, 7);
	list2_head = NULL;
	list2_head = insert_at_head(list2_head, 24);
	list1_head = append_list(list1_head, list2_head);
	print_list(list1_head);
	free(list1_head);
	free(list2_head);
}
