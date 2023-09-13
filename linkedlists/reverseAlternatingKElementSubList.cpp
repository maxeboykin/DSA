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
    ListNode *reverse(ListNode *head, int k) {
        if(k <= 1) return head;
        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(true){
            ListNode* lastNodeOfPrevPart = prev;
            ListNode* lastNodeOfSublist = current;
            for(int i = 0; i < k && current != nullptr; i++){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            if(lastNodeOfPrevPart == nullptr){
                head = prev;
            } else {
                lastNodeOfPrevPart->next = prev;
            }
            lastNodeOfSublist->next = current;
            if(current == nullptr) break;
            prev = lastNodeOfSublist;
            for(int i = 0; i < k && current != nullptr; i++){
                next = current->next;
                prev = current;
                current = next;
            }
            if(current == nullptr || current->next == nullptr){
                return head;
            }
        }
        return head;
    }
    ListNode* calculateTime(ListNode *head, int k){
        clock_t start;
        clock_t end;
        start = clock();
        ListNode* result = reverse(head, k);
        end = clock();
        printf("Reverse Alternating K-element SubList Linked List: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(ListNode* expected, ListNode* actual){
        std::cout << "Reverse Alternating K-element Sublist Linked List: ";
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
    foo->insertAtEnd(6);
    foo->insertAtEnd(7);
    foo->insertAtEnd(8);
    int k = 2;
    LinkedList* expected = new LinkedList();
    expected->insertAtBeginning(2);
    expected->insertAtEnd(1);
    expected->insertAtEnd(3);
    expected->insertAtEnd(4);
    expected->insertAtEnd(6);
    expected->insertAtEnd(5);
    expected->insertAtEnd(7);
    expected->insertAtEnd(8);
    ListNode *result = solution.reverse(foo->head, k);
    solution.printExpectations(expected->head, result);
}
