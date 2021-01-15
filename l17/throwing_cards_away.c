#include<stdio.h>
#include<stdlib.h>

struct element{
	int data;
	struct element *next;
};

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	struct element *head, *prev, *curr, *new_node;
	new_node = malloc(sizeof(struct element));
	new_node->data = 1;
	head = new_node;
	curr = new_node;
	for(int i = 2; i <= n; i++){
		new_node = malloc(sizeof(struct element));
		new_node->data = i;
		curr->next = new_node;
		curr = curr->next;
	}
	curr->next = head;
	prev = curr;
	curr = curr->next;
	//curr = curr->next;//curr = head
	for(int i = 1; i <= m; i++){
		printf("%d ", curr->data);
		curr = curr->next;
		prev->next = curr;
		prev = curr;
		curr = curr->next;
	}
	return 0;
}
