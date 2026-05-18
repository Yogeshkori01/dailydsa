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

ListNode* reverseList(ListNode* head) {

    ListNode* prev = NULL;
    ListNode* curr = head;

    while(curr != NULL) {

        ListNode* nextNode = curr->next;

        curr->next = prev;

        prev = curr;

        curr = nextNode;
    }

    return prev;
}

bool isPalindrome(ListNode* head) {

    if(head == NULL || head->next == NULL) {
        return true;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next != NULL && fast->next->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* secondHalf = reverseList(slow->next);

    ListNode* firstHalf = head;

    while(secondHalf != NULL) {

        if(firstHalf->val != secondHalf->val) {
            return false;
        }

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    if(isPalindrome(head)) {
        cout << "Palindrome" << endl;
    }
    else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}