#include <stdio.h>

/* thread safe linked list implementation. */
struct list_nodes_s {
	int data;
	struct list_node_s * next;
	pthread_mutex_t mutex;
}

struct list_node_s * head_p;

// this implementation is inefficient except in mean function.

// one mutex per node implementation
int Member( int value ) {
	struct list_node_s * temp_p;

	pthread_mutex_lock(&head_p_mutex);
	temp_p = head_p;

	while( temp_p  != NULL && temp_p->data < value) {
		if( temp_p->next != NULL )
		{
			pthread_mutex_lock(&(temp_p->next->mutex);
		}
		if( temp_p == head_p ) {
			pthread_mutex_unlock(&head_p_mutex);
		}
		pthread_mutex_unlock(&(temp_p->mutex);
		temp_p = temp->next;
	}

	if( temp_p == NULL || temp_p->data > value ) {
		if( temp_p == head_p )
			pthread_mutex_unlock(&head_p_mutex);
		if( temp_p != NULL  )
			pthread_mutex_unlock(&(temp_p->mutex));
		return 0;
	} else {
		if( temp_p == head_p )
			pthread_mutex_unlock(&head_p_mutex);
		pthread_mutex_unlock(&(temp_p->mutex));
		return 1;
	}

}

int Insert( int value )
{

	struct list_nodes_s* curr_p = *head_p;
	struct list_nodes_s* pred_t = NULL;
	struct list_nodes_s* temp_p;

	pthread_mutex_lock( &(curr_p->mutex) );

	while( curr_p != NULL && curr_p->data < value ) {

		temp_p = pred_p;
		pred_p = curr_p;
		if(curr_p->next != NULL)
			pthread_mutex_lock(&(curr_p->next->mutex);
		curr_p = curr_p->next;
		// pthread_mutex_unlock(&(curr_p->mutex));
		if ( temp_p != NULL)
			pthread_mutex_unlock( &(temp_p) );

	}

	if( curr_p == NULL || curr_p->data > value  ) {

		temp_p = malloc(sizeof(struct list_nodes_s));
		temp_p->data = value;
		temp_p->next = curr_p;
		pthread_mutex_unlock(&(curr_p));
		
		if (pred_p == NULL)
		{	
			pthread_mutex_lock(&(head_p));
			*head_p = temp_p;
			pthread_mutex_unlock(&(head_p));
		}
		
		else 
		{	
		
			pred_p->next = temp_p;
		}
		
		pthread_mutex_unlock(&(pred_p));
		return 1;
	} else {
		
		return 0;
	}

}

int Delete ( int value )
{

	pthread_mutex_lock(&(head_p));
	struct list_node_s* curr_p = *head_p;
	struct list_node_s* pred_p = NULL;
	struct list_node_s* tmp_p ;
	while (curr_p != NULL && curr_p ->data < value) {
		tmp_p = pred_p;
		pred_p = curr_p;
		if(curr_p != NULL){
			pthread_mutex_lock(&curr_p);
		}
		curr_p = curr_p ->next;
		pthread_mutex_unlock(&tmp_p);
	}
	if (curr_p != NULL && curr p->data == value) {
		if (pred_p == NULL) { /* Deleting first node in list */
			∗head_p = curr_p -> next;
			free(curr_p);
		} else {
			pred_p -> next = curr_p -> next;
			free(curr_p);
		}
		pthread_mutex_unlock(&pred_p);
		pthread_mutex_unlock(&tmp_p);
		return 1;
	} else { /* Value isn’t in list */
		return 0;
	}
}


int main(int argc, char* argv[])
{
	// multiple member function does not need lock if
	// insertion and deletion is more then it need to optimize
	//
	//
	
	Member(1);// members are paralleizi
	Member(5);
	Member(6);
	//...
	pthread_mutex_lock(&list_mutex);
	Insert(2);
	pthread_mutex_unlock(&list_mutex);
	
	//...
	return 0;
}
