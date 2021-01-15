#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;
void MoveToTail();

int main(void) { 
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        struct node* tmp = malloc(sizeof(struct node));
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        if(i == 1)
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
    }
    MoveToTail();
    for(struct node* cur = head; cur != NULL; cur = cur->next)
        printf("%d ", cur->val); 
    return 0;
}
// Your code goes here
void MoveToTail(){
	//if (head->next == NULL);
	//else{
	int x;
	x = head->val;
	struct node *curr, *prev;
	curr = head;
	while(curr != NULL){
		if(curr->val > x) x = curr->val;
		curr = curr->next;
	}
	curr = head;
	while(!(curr->val == x)){
		prev = curr;
		curr = curr->next;
	}
	if(curr->next == NULL);
	else if(head == curr){
		head = curr->next;
		tail->next = curr;
		curr->next = NULL;
	}
	else{
		prev->next = curr->next;
		tail->next = curr;
		curr->next = NULL;
	}
	//}
}
