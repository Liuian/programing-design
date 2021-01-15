#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct element {                // elements of the stack
        int data;
        struct element *next;   // point to the next element in the stack
};

struct head {
        int size;               // record the size of the stack
        struct element *next;   // point to the first element (at bottom) in the stack if there is any
        struct element *top;    // point to the top of the stack
};

void print_stack(struct head *stack_p);
void push(struct head *stack_p, int data);      // put an element to the top of the stack
struct element *pop(struct head *stack_p);      // remove an element from the top of the stack

int main(void) {
        // stack declaration
        struct head stack_head;
        stack_head.size = 0;
        stack_head.next = NULL;
        stack_head.top = NULL;

        // read instructions
        int num, data;
        char command[5];
        scanf("%d", &num);
        for (int i = 0; i < num; ++i) {
                scanf("%4s", command);
                if (strcmp(command, "push") == 0) {     // push command, call push()
                        scanf("%d", &data);
                        push(&stack_head, data);
                }
                else if (strcmp(command, "pop") == 0) { // pop command, call pop()
                        struct element *e = pop(&stack_head);
                        free(e);
                }
        }
        print_stack(&stack_head);
        return 0;
}

void print_stack(struct head *stack_p) {
        printf("%d\n", stack_p->size);
        for (struct element *ptr = stack_p->next; ptr != NULL; ptr = ptr->next)
                printf("%d ", ptr->data);
}


// Your code goes here
void push(struct head *stack_p, int data){      // put an element to the top of the stack
	stack_p->size += 1;
	struct element *new = malloc(sizeof(struct element));//struct element new;//建一個新的node
	new->data = data;   //新node存入data
	new->next = NULL;
	if(stack_p->next == NULL){        //是第一個node的處理方式
		stack_p->next = new;
		stack_p->top = new;
	}
	else{                                //不是第一個node的處理方式
		(stack_p->top)->next = new;
		stack_p->top = new;
	}
}
struct element *pop(struct head *stack_p){      // remove an element from the top of the stack
	stack_p->size -= 1;
	struct element *curr;
	curr = stack_p->next;                                //curr指定到第一個element
	//如果是最後一個node
	if(curr == stack_p->top){
		stack_p->top = NULL;
		stack_p->next = NULL;
		return curr;
	}
	//不是最後一個node
	else{
		while(curr->next != stack_p->top) curr = curr->next; //找到top的前一個element
		stack_p->top = curr;                                 //top往回退一個
		curr = curr->next;
		stack_p->top->next = NULL;
		return curr;
	}
}
