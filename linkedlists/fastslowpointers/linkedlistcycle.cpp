#include <iostream>

class ListNode {
public:
    int val = 0;
    ListNode *next; // pointer to type ListNode

    ListNode(int value) { // constructor
        this->val = value;
        next = nullptr;
    }
};

class LinkedListCycle {
public:
    static bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        bool firstIteration = true;
//        while(slow != nullptr && fast != nullptr){ i made this mistake and got a segmentation fault
        // remember to check it fast->next is not null too
        while(fast != nullptr && fast->next != nullptr){
        if(slow == fast && !firstIteration) return true;
        firstIteration = false;
        slow = slow->next;
        fast = fast->next->next; // this will throw if fast->next is not evaluated above
        }
        return false;
    }
};

// figure out how to test
int main(){
    LinkedListCycle solution;

}


