#include <stdio.h>
#include <stdlib.h>

#define INT_MIN -2147483648

struct Node {
    int val;
    struct Node* next;
};

struct Node* Front;
struct Node* Rear;
int Sz;

void init()
{
    Sz = 0;
    Front = NULL;
    Rear = NULL;
}

void QInsertVal(int val)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));

    node->val = val;
    node->next = NULL;

    Sz++;

    if(Rear == NULL) {
        Rear = node;
        Front = Rear;
    }
    else {
        Rear->next = node;
        Rear = node;
    }
}

int QFront()
{
    if(Front == NULL) {
        printf("Queue is empty.\n");
        return INT_MIN;
    }

    return Front->val;
}

void QDelete()
{
    if(Front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Front = Front->next;
    Sz--;
}

void QPrint()
{
    struct Node* node = Front;

    if(Front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("All element in Queue:\n");

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
        printf("Press 1 to insert 2 to see the front 3 to delete 4 to display all element 5 to length 6 to exit.\n");

        int choice;

        scanf("%d", &choice);

        if(choice == 1) {
            int val;
            printf("Insert element:\n");
            scanf("%d", &val);
            QInsertVal(val);
        }
        if(choice == 2) {
            int val = QFront();
            printf("Front element: %d\n", val);
        }

        if(choice == 3) {
            QDelete();
        }

        if(choice == 4) {
            QPrint();
        }

        if(choice == 5) {
            printf("Current size of the queue: %d\n", Sz);
        }

        if(choice == 6) {
            return 0;
        }
    }

    return 0;
}

