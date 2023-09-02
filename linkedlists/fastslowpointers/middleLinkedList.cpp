#include <iostream>

class ListNode {
public:
    int val = 0;
    ListNode *next;

    ListNode(int value) {
        this->val = value;
        this->next = nullptr;
    }
};

class MiddleLinkedList {
public:
   ListNode *findMiddle(ListNode *head) {
       ListNode *fast = head;
       ListNode *slow = head;
       while(fast != nullptr && fast->next != nullptr){
           slow = slow->next;
           fast = fast->next->next;
       }
       return slow;
   }
};

int main(){
    MiddleLinkedList solution;
}