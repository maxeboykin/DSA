class ListNode {
public:
    int val = 0;
    ListNode *next;

    ListNode(int value){
        this->val = value;
        this->next = nullptr;
    }
};

class FindLinkedListStart {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        int cycleLength = 0;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                cycleLength = findLength(slow);
                break;
            }
        }
        if(cycleLength == 0) return nullptr;
        return calculateStart(head, cycleLength);
    }
private:
    static int findLength(ListNode *left){
        ListNode *right = left;
        int count = 0;
        bool firstIteration = true;
        while(firstIteration || left != right){
            firstIteration = false;
            count++;
            right = right->next;
        }
        return count;
    }
    static ListNode* calculateStart(ListNode *head, int cycleLength){
        // advance right pointer
        ListNode *right = head;
        ListNode *left = head;
        for(int i = 0; i < cycleLength; i++){
            right = right->next;
        }
        while(left != right){
            left = left->next;
            right = right->next;
        }
        return left; // could also return right
    }
};