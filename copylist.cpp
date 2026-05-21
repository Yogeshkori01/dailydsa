]#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int data) {
        val = data;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {

    if(head == NULL) {
        return NULL;
    }

    unordered_map<Node*, Node*> mp;

    Node* temp = head;

    while(temp != NULL) {

        mp[temp] = new Node(temp->val);

        temp = temp->next;
    }

    temp = head;

    while(temp != NULL) {

        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];

        temp = temp->next;
    }

    return mp[head];
}

void printList(Node* head) {

    while(head != NULL) {

        cout << "Node: " << head->val;

        if(head->random != NULL) {
            cout << " Random: " << head->random->val;
        }
        else {
            cout << " Random: NULL";
        }

        cout << endl;

        head = head->next;
    }
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next;

    Node* copiedList = copyRandomList(head);

    printList(copiedList);

    return 0;
}