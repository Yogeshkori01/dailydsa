#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int data) {
        val = data;
        next = NULL;
    }
};

ListNode* rotateRight(ListNode* head, int k) {

    if(head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    ListNode* temp = head;
    int length = 1;

    while(temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    temp->next = head;

    k = k % length;

    int steps = length - k;

    while(steps--) {
        temp = temp->next;
    }

    head = temp->next;

    temp->next = NULL;

    return head;
}

void printList(ListNode* head) {

    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    cout << "Original List: ";
    printList(head);

    head = rotateRight(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}