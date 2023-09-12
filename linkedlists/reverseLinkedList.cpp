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

class ReverseLinkedList {
public:
    ListNode *reverse(ListNode *head) {
        ListNode *current = head;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        while(current != nullptr){
            next = current->next; // need to hold onto next before changing current->next
            current->next = prev; // main part of the loop
            prev = current;       // move everything up
            current = next;       // move everything up current is last since its while case
        }
        return prev;
    }
    ListNode* calculateTime(ListNode *head){
        clock_t start;
        clock_t end;
        start = clock();
        ListNode* result = reverse(head);
        end = clock();
        printf("Reverse Linked List: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(ListNode* expected, ListNode* actual){
        std::cout << "Reverse Linked List: ";
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
    ReverseLinkedList solution;
    LinkedList* foo = new LinkedList();
    foo->insertAtBeginning(1);
    foo->insertAtEnd(2);
    foo->insertAtEnd(3);
    foo->insertAtEnd(4);
    foo->insertAtEnd(5);
    LinkedList* expected = new LinkedList();
    expected->insertAtBeginning(5);
    expected->insertAtEnd(4);
    expected->insertAtEnd(3);
    expected->insertAtEnd(2);
    expected->insertAtEnd(1);

    ListNode *result = solution.reverse(foo->head);
    solution.printExpectations(expected->head, result);
}