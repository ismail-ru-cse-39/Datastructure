#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int key;
    int val;

    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *last = NULL;
struct node *current = NULL;

bool isEmpty()
{
    return head == NULL;
}

int lenght()
{
    int len = 0;

    struct node *cur = head;

    while(cur != NULL) {
        len++;
        cur = cur->next;
    }

    return len;
}


void displayForward()
{
    struct node *cur = head;

    printf("Displaying the list in forwarding order.\n");

    while(cur != NULL) {
        printf("(%d %d), ", cur->key, cur->val);
        cur = cur->next;
    }

    printf("\n");
}

void displayBackward()
{
    struct node* ptr = last;

    printf("Printing the list in back warding order\n");

    while(ptr != NULL) {
        printf("(%d %d), ", ptr->key, ptr->val);
        ptr = ptr->prev;
    }

    printf("\n");
}

void insertFirst(int key, int val)
{
    struct node *n = (struct node*) malloc(sizeof(struct node));

    n->key = key;
    n->val = val;
    n->next = NULL;
    n->prev = NULL;

    if(isEmpty()) {
        last = n;
    } else {
        head->prev = n;
    }
    n->next = head;

    head = n;
}


void insertLast(int key, int val)
{
    struct node *nd = (struct node*) malloc(sizeof(struct node));

    nd->key = key;
    nd->val = val;

    if(isEmpty()) {
        last = nd;
    } else {
        last->next = nd;
    }
    nd->prev = last;

    last = nd;
}

struct node* deleteFirst()
{
    struct node *tmp = head;

    if(head->next == NULL) {
        last = NULL;
    } else {
        head->next->prev = NULL;
    }
    head = head->next;

    //Return the deleted link
    return tmp;
}


struct node* deleteLast()
{
    struct node * tmp = last;

    if(head->next == NULL) {
        head = NULL;
    } else {
        last->prev->next = NULL;
    }

    last = last->prev;

    //Returning the deleted node
    return tmp;
}

struct node* deleteWithKey(int key)
{
    struct node* cur = head;
    struct node* prev = NULL;

    if(head == NULL)
    {
        return NULL;
    }

    while(cur->key != key) {
        if(cur->next == NULL) {
            return NULL;
        }

        prev = cur;
        cur = cur->next;
    }


    if(cur == head) {
        head = cur->next;
    } else {
        cur->prev->next = cur->next;
    }

    if(cur == last) {
        last = last->prev;
    } else {
        cur->next->prev = cur->prev;
    }

    return cur;
}


bool insertAfter(int key, int newKey, int val)
{
     struct node* cur = head;

     if(head == NULL) {
        return false;
     }

     while(cur->key != key) {
        if(cur->next  == NULL) {
            return false;
        }

        cur = cur->next;
     }

     struct node* nd = (struct node*) malloc(sizeof(struct node));
     nd->key = newKey;
     nd->val = val;

     if(cur == last) {
        nd->next = NULL;
        last = nd;
     } else {
        nd->next = cur->next;
        cur->next->prev = nd;
     }

     nd->prev = cur;
     cur->next = nd;

     return true;
}

int main() {
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56);

   printf("\nList (First to Last): ");
   displayForward();

   printf("\n");
   printf("\nList (Last to first): ");
   displayBackward();

   printf("\nList , after deleting first record: ");
   deleteFirst();
   displayForward();

   printf("\nList , after deleting last record: ");
   deleteLast();
   displayForward();

   printf("\nList , insert after key(4) : ");
   insertAfter(4,7, 13);
   displayForward();

   printf("\nList  , after delete key(4) : ");
   deleteWithKey(4);
   displayForward();


   return 0;
}
