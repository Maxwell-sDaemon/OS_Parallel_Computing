#include <stdio.h>
#include <stdlib.h>

struct list_nodes_s {
	int data;
	struct list_node_s * next;
}

int Member(int value, struct list_nodes** head_p)
{
	struct list_nodes_s * curr_p = head_p;
	
	while( curr_p != NULL && curr_p->data < value) 
		curr_p = curr_p->next;

	if ( curr_p == NULL && curr_p->data > value )
	{
		return 0;
	}
	else 
	{
		return 1;
	}

} /* Member */

int Insert(int value, struct list_nodes_s** head_p)
{
	struct list_nodes_s* curr_p = *head_p;
	struct list_nodes_s* pred_t = NULL;
	struct list_nodes_s* temp_p;

	while( curr_p != NULL && curr_p->data < value ) {
		pred_p = curr_p;
		curr_p = curr_p->next;	
	}

	if( curr_p == NULL || curr_p->data > value  ) {
		temp_p = malloc(sizeof(struct list_nodes_s));
		temp_p->data = value;
		temp_p->next = curr_p;
		if (pred_p == NULL) 
			 *head_p = temp_p;
		else
			pred_p->next = temp_p;
		return 1;		
	} else {
		return 0;
	}
}

int Delete(int value, struct list node s** head p) {
	struct list node s* curr p = *head p;
	struct list node s* pred p = NULL;
	while (curr p != NULL && curr_p ->data < value) {
		pred_p = curr_p;
		curr_p = curr_p ->next;
	}
	if (curr p != NULL && curr p->data == value) {
		if (pred p == NULL) { /* Deleting first node in list */
			∗head_p = curr_p -> next;
			free(curr_p);
		} else {
			pred_p -> next = curr_p -> next;
			free(curr_p);
		}
		return 1;
	} else { /* Value isn’t in list */
		return 0;
	}
}/* Delete */

int main(int argc, char* argv[])
{
	

	return 0;
}

