#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node* next;
	int value;
};

struct node * insert(struct node *head, struct node *cur,int value){
	if(head==NULL){
		struct node *p;
		p = (struct node*)malloc(sizeof(struct node));
		p->next = NULL;
		p->value = value;
		head = p; 
		return head;
	}
	else if (cur!=NULL){
		if(cur->next != NULL){
			insert(head, cur->next ,value);
		}
		else if(cur->next == NULL){
			struct node *p;
			p = (struct node*)malloc(sizeof(struct node));
			p->next = NULL;
			p->value = value;
			cur->next = p;
			//return head ;
		}
	}
	return head;
}

struct node * delete(struct node *head, int value){
	if(head != NULL){
		if(head->value == value){
			struct node * ptr = head->next;
			free(head);
			return ptr;
		}
		else {
			struct node * pre = NULL;
			struct node * cur = head;
			while(cur != NULL){
				pre = cur;
				cur = cur->next;
				if( cur->value == value){
					pre->next = cur->next;
					free(cur);
					return head;
				}
			}
		}
		return NULL;
	}
}

void list(struct node* head){
	if(head!=NULL){
		printf("val %d\n", head->value);
		list(head->next);
	}
	else
		return;
}

void find(struct node* head, int value){
	if(head != NULL){
		if (head->value == value){
			printf("find val: %d\n", head->value);
		}
		else
			find(head->next, value);
	}
}

int main()
{
	struct node * head=NULL;
	head = insert(head, head, 1);
	head = insert(head, head, 2);
	head = insert(head, head, 3);
	head = insert(head, head, 4);
	head = insert(head, head, 5);
	head = insert(head, head, 6);
	head = insert(head, head, 7);
	list(head);
	find(head, 2);
	head = delete(head, 1);
	head = delete(head, 2);
	head = delete(head, 7);
	list(head);
	return 0;
}
