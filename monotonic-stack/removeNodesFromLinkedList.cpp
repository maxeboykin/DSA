#include <iostream>
#include <vector>
#include <stack>

class ListNode {
public:
    int value = 0;
    ListNode* next;

    ListNode(int val){
        this->value = val;
        this->next = nullptr;
    }
    ListNode(int val, ListNode* nxt){
        this->value = val;
        this->next = nxt;
    }
};

struct ListNodeS {
    int value = 0;
    ListNode* next;
    ListNodeS(){this->value = 0;this->next = nullptr;}
    ListNodeS(int val){this->value = val;this->next = nullptr;}
    ListNodeS(int val, ListNode* nxt){this->value = val;this->next = nxt;}
};

class RemoveNodesFromLinkedList{
public:
ListNode* removeNodes(ListNode* head) {
    std::stack<ListNode*> stack;
    ListNode* cur = head;
    while(cur != nullptr){
        while(!stack.empty() && stack.top()->value < cur->value){
            stack.pop();
        }
        if(!stack.empty()){
            stack.top()->next = cur;
        }
        stack.push(cur);
        cur = cur->next;
    }
    while(!stack.empty()){
        cur = stack.top();
        stack.pop();
    }
    return cur;
}

    ListNode* calculateTime(ListNode* head){
        clock_t start;
        clock_t end;
        start = clock();
        ListNode* result = removeNodes(head);
        end = clock();
        printf("Remove Nodes From Linked List: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }

    void printExpectations(ListNode* expected, ListNode* actual){
        std::cout << "Remove Nodes From Linked List: ";
        std::cout << "Expected: " << std::endl;
        printLinkedList(expected);
        std::cout << "Actual: " << std::endl;
        printLinkedList(actual);
    }
    void printLinkedList(ListNode* head){
        ListNode *temp = head;
        while(temp != nullptr){
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main(){
    RemoveNodesFromLinkedList solution;
    // Creating the linked list 5 -> 3 -> 7 -> 4 -> 2 -> 1
    ListNode* head1 = new ListNode(5);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(7);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(2);
    head1->next->next->next->next->next = new ListNode(1);
    head1 = solution.calculateTime(head1);

    ListNode* expect1 = new ListNode(7);
    expect1->next = new ListNode(4);
    expect1->next->next = new ListNode(2);
    expect1->next->next->next = new ListNode(1);
    solution.printExpectations(expect1, head1);

}
