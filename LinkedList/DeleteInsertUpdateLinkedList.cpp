#include <stdio.h>
#include<stdlib.h>


typedef struct node{
    int val;
    struct node* next;

}Node;

Node *Root;

void init() {
    Root =(Node*) malloc(sizeof(Node));
    Root->next = NULL;
}

void insertFirst(int val) {

    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = Root;

    Root = node;

}

void insertNode(int val) {

    Node* ptr = Root;

    //printf("InsertNode()\n");

    while(ptr->next != NULL) {

        ptr = ptr->next;

    }


    Node* node = (Node*) malloc(sizeof(Node));


    node->val = val;
    node->next = NULL;


    ptr->next = node;

     //printf("InsertNode(->while()\n");

}

int findVal(int val) {

    Node* ptr = Root;

    if(ptr!=NULL) {
        ptr = ptr->next;
    }

    while(ptr!=NULL) {
        if(ptr->val == val) {
            return 1;
        }
        ptr = ptr->next;
    }

    return 0;

}


/* void print()
 {
     Node* ptr = Root;

     if(ptr==NULL) {
        printf("Root is null\n");
     }

     if(ptr->next == NULL) {
        printf("root->next is null\n");
     }

     while(ptr->next != NULL) {
        printf("%d, ", ptr->next->val);
        ptr = ptr->next;
     }

     printf("\n");
 }
*/


void deletNode(int val)
{
    Node* ptr = Root;
   /* if(ptr!=NULL) {
        ptr = ptr->next;
    }*/

    while(ptr->next != NULL) {
        if(ptr->next->val == val) {
            ptr->next = ptr->next->next;
            return;
        }
        ptr = ptr->next;
    }

}

void print()
 {
     Node* ptr = Root;

     if(ptr==NULL) {
        printf("Root is null\n");
        return;
     }

     if(ptr!= NULL) {
        ptr = ptr->next;
     }

     while(ptr != NULL) {
        printf("%d, ", ptr->val);
        ptr = ptr->next;
     }

     printf("\n");
 }


int main()
{
    init();
    //printf("Hello world.\n");

    for(int i = 0; i < 20; i++) {
        insertNode(i);
    }

    print();

    printf("%d\n", findVal(20));

    printf("%d\n", findVal(19));

    deletNode(0);
    deletNode(19);
    deletNode(10);

    print();

    return 0;
}
