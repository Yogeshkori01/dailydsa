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

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

    if(headA == NULL || headB == NULL) {
        return NULL;
    }

    ListNode* a = headA;
    ListNode* b = headB;

    while(a != b) {

        if(a == NULL) {
            a = headB;
        }
        else {
            a = a->next;
        }

        if(b == NULL) {
            b = headA;
        }
        else {
            b = b->next;
        }
    }

    return a;
}

int main() {

    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(6);
    headA->next->next = common;

    ListNode* headB = new ListNode(4);
    headB->next = common;

    ListNode* intersection = getIntersectionNode(headA, headB);

    if(intersection != NULL) {
        cout << "Intersection Node: " << intersection->val << endl;
    }
    else {
        cout << "No Intersection" << endl;
    }

    return 0;
}