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

class LinkedList {
public:
    ListNode *head;
    LinkedList() {
        this->head = nullptr;
    }
    void insertAtBeginning(int val) {
        ListNode *newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int val) {
        ListNode *newNode = new ListNode(val);
        if(head == nullptr){
            head = newNode;
            return;
        }
        ListNode *temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void deleteAtBeginning(){
        if(head == nullptr){
            return;
        }
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
    void deleteAtEnd(){
        if(head == nullptr){
            return;
        }
        if(head->next == nullptr){
            delete head;
            head = nullptr;
        }
        ListNode *temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    void printList(){
        ListNode *temp = head;
        while(temp != nullptr){
            std::cout <<temp->val << "";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

};

class ReverseSublist {
public:
    ListNode *reverseSublist(ListNode *head, int p, int q) {
        if(p == q) return head;
        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        int i = 1;
        for(; current != nullptr && i < p; i++){
            prev = current;
            current = current->next;
        }
        ListNode* pNode = current;      // lastNodeOfSublist
        ListNode* pMinusOneNode = prev; // lastNodeOfFirstPart
        /*
        // need to move current and prev up one to start reversal since we dont want to reverse one too early
        // it actually doesn't matter since it gets clobbered when we change p and q at the end
          prev = prev->next;
          current = current->next;
          i++;
        */
        for(;current != nullptr && i <= q; i++){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        // current is q+1 and previous is q
        if(pMinusOneNode != nullptr){
            pMinusOneNode->next = prev;
        } else {
            head = prev;
        }
        pNode->next = current;
        return head;
    }
    ListNode* calculateTime(ListNode *head, int p, int q){
        clock_t start;
        clock_t end;
        start = clock();
        ListNode* result = reverseSublist(head, p, q);
        end = clock();
        printf("Reverse SubList Linked List: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(ListNode* expected, ListNode* actual){
        std::cout << "Reverse Sublist Linked List: ";
        std::cout << "Expected: " << std::endl;
        printLinkedList(expected);
        std::cout << "Actual: " << std::endl;
        printLinkedList(actual);
    }
    void printLinkedList(ListNode* head){
        ListNode *temp = head;
        while(temp != nullptr){
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};


int main(){
    ReverseSublist solution;
    LinkedList* foo = new LinkedList();
    foo->insertAtBeginning(1);
    foo->insertAtEnd(2);
    foo->insertAtEnd(3);
    foo->insertAtEnd(4);
    foo->insertAtEnd(5);
    LinkedList* expected = new LinkedList();
    expected->insertAtBeginning(1);
    expected->insertAtEnd(4);
    expected->insertAtEnd(3);
    expected->insertAtEnd(2);
    expected->insertAtEnd(5);
    int p = 2;
    int q = 4;
    ListNode *result = solution.reverseSublist(foo->head, p, q);
    solution.printExpectations(expected->head, result);
}