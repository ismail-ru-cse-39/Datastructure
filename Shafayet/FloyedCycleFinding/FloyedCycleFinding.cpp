#include<iostream>

using namespace std;

struct Node{
    Node* next;
    int val;

    Node(int _val) {
        val = _val;
        next = NULL;
    }
};

#define SZ 100000

Node *Root = NULL;

void insertFirst(int val) {
    Node* newNode = new Node(val);

    if(Root == NULL) {
        Root = newNode;
    } else {
        newNode->next = Root;
        Root = newNode;
    }
}

bool detectCycle(Node *hare, Node *tortoise) {
    if(hare->next == NULL) {
        return false;
    }

    while(hare) {
        if(hare->next && hare->next->next) {
            hare = hare->next->next;
        } else {
            return false;
        }
        tortoise = tortoise->next;

        if(hare == tortoise) {
            return true;
        }
    }

    return false;
}

Node*  startNode(Node* tortoise2, Node* tortoise) {
    while(tortoise != tortoise2) {
        tortoise = tortoise->next;
        tortoise2 = tortoise2->next;
    }

    return tortoise;
}

/*
void print() {
    Node* node = Root;
    while(node) {
        cout<<node->val<<endl;
        node = node->next;
    }

}*/

int main()
{
    Root = NULL;
    freopen("input.txt","r", stdin);
    int n;
    cin>>n;
    while(n--) {

        int val;
        cin>>val;
        insertFirst(val);
    }

    // adding a loop for the sake
    // of this example
    Node* temp = Root;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = Root;

    // loop added;

    Node* hare = Root;
    Node* tortoise = Root;
    Node* cycleStart = NULL;

    if(detectCycle(hare, tortoise)) {
        cout<<"cycle detected"<<endl;
        Node* tortoise2 = Root;
        cycleStart = startNode(tortoise2, tortoise);
    }

   cout<<"Cycle Start at: "<<cycleStart->val<<endl;

    return 0;

}
