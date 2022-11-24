#include "list.h"

int	main(void)
{
	t_Node	*list1_head;
	int		num_deleted;

	list1_head = NULL;
	list1_head = insert_at_head(list1_head, 7);
	list1_head = insert_at_tail(list1_head, 22);
	list1_head = insert_at_tail(list1_head, 22);
	list1_head = insert_at_tail(list1_head, 4);
	list1_head = insert_at_tail(list1_head, 7);
	printf("BEFORE : \n");
	print_list(list1_head);
	list1_head = efficient_delete_match(list1_head, 7, &num_deleted);
	if (num_deleted > 0)
		printf("\nWAS DELETED : TRUE * %d\n", num_deleted);
	else
		printf("\nWAS DELETED : FALSE\n");
	printf("\nAFTER : \n");
	print_list(list1_head);
}
