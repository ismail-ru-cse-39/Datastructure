#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

struct Node* Start;
struct Node* End;
int Sz;

void init()
{
    Start = NULL;
    End = NULL;
    Sz = 0;
}

void push(int val) {

     Sz++;
     struct Node* node = (struct Node*) malloc(sizeof(struct Node));
     node->val = val;

     if(Start == NULL) {
        Start = node;
        Start->next = NULL;
        return;
     }
    node->next = Start;
    Start = node;
}

int top()
{
    if(Start == NULL) {
        printf("No element in the list.\n");
        return -9999;
    }

    return Start->val;
}

void pop()
{
    if(Start == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    Start = Start->next;
}

void printStack()
{
    struct Node *node = Start;

    if(Start == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    while(node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }

    printf("\n");
}

int main()
{
    init();
    while(true) {
        int choice;
        printf("Press 1 to push, 2 to see top 3 to pop and 4 to print the Stack 5 to exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            int val;
            printf("Enter the val.\n");
            scanf("%d", &val);
            push(val);
        }

        if(choice == 2) {
            int topVal = top();
            printf("Current top value : %d\n", topVal);
        }

        if(choice == 3) {
            pop();
        }

        if(choice == 4){
            printf("All elements of stack: \n");
            printStack();
        }

        if(choice == 5) {
            return 0;
        }

    }


    return 0;
}
