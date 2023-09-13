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
      if(k <= 1 || head == nullptr) return head;
      ListNode* current = head;
      ListNode* prev = nullptr;
      ListNode* next = nullptr;
      while(true){
          ListNode* lastNodeOfPreviousPart = prev;
          ListNode* lastNodeOfSublist = current; //first node in group will be last
          for(int i = 0; current != nullptr && i < k; i++){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
          }
          if(lastNodeOfPreviousPart == nullptr){
              head = prev;
          } else {
              lastNodeOfPreviousPart->next = prev; // corresponds to line 92 as well
          }
          lastNodeOfSublist->next = current; // current is first node in next group which will change  in line 90 again above in next sublist
          if(current == nullptr) break;
          prev = lastNodeOfSublist; // helps connect the first node in next group point to first node in previous group
      }
        return head;
    }
    ListNode* calculateTime(ListNode *head, int k){
        clock_t start;
        clock_t end;
        start = clock();
        ListNode* result = reverse(head, k);
        end = clock();
        printf("Reverse Every K-element SubList Linked List: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(ListNode* expected, ListNode* actual){
        std::cout << "Reverse Every K-element Sublist Linked List: ";
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
    int k = 3;
    LinkedList* expected = new LinkedList();
    expected->insertAtBeginning(3);
    expected->insertAtEnd(2);
    expected->insertAtEnd(1);
    expected->insertAtEnd(6);
    expected->insertAtEnd(5);
    expected->insertAtEnd(4);
    expected->insertAtEnd(8);
    expected->insertAtEnd(7);
    ListNode *result = solution.reverse(foo->head, k);
    solution.printExpectations(expected->head, result);
}

/* my first approach - close but not all test cases
 * ListNode *reverse(ListNode *head, int k) {
      ListNode* prev = nullptr;
      ListNode* next = nullptr;
      ListNode* current = head;
      ListNode* first = nullptr;
      ListNode* temp = nullptr;
      bool firstIteration = true;

      for(int i = 1; current != nullptr; i++){
          if(i % k == 1){
              first = current;
              next = current->next;
              current->next = prev;
              prev = current;
              current = next;
          } else if(i % k == 0){
              if(firstIteration){
                  head = current;
                  firstIteration = false;
              }
              temp = current;
              for(int j = 1; j <= k && temp->next != nullptr; j++){
                  temp = temp->next;
              }
              first->next = temp;
              next = current->next;
              current->next = prev;
              prev = nullptr; // super imp
              current = next;
          } else {
              next = current->next;
              current->next = prev;
              prev = current;
              current = next;
          }
      }
      return head;
    }
 *
 */