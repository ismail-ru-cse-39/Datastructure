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

int main()
{
    init();

    int val;
    scanf("%d", &val);
    push(val);
    int value = top();
}
