#include <iostream>
#include <vector>
#include <queue>

class TreeNode {
public:
    int val = 0;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next; // this is new!

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
        next = nullptr;
    }
};

// queue methods include empty, size, front, back, push, pop
class ConnectLevelOrderSiblings{
public:
    static TreeNode* connect(TreeNode *root) {
        std::queue<TreeNode *> queue = {};
        queue.push(root);
        while(!queue.empty()){
            int curLevelSize = queue.size();
            TreeNode* prevNode = nullptr;
            for(int i = 0; i < curLevelSize; i++){
                TreeNode* curNode = queue.front();
                queue.pop();
                if(prevNode != nullptr) {
                    prevNode->next = curNode;
                }
                if(curNode->left != nullptr) queue.push(curNode->left);
                if(curNode->right != nullptr) queue.push(curNode->right);
                prevNode = curNode;
            }
            prevNode->next = nullptr;
        }
        return root;
    }
    static TreeNode* calculateTime(TreeNode *root){
        clock_t start;
        clock_t end;
        start = clock();
        TreeNode* result = connect(root);
        end = clock();
        printf("Connect Level Order Siblings: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    static void printExpectations(int expected, int actual){
        std::cout << "Connect Level Order Siblings: ";
        std::cout << "Expected: " << expected << std::endl;
        std::cout << "Actual: " << actual << std::endl;
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    ConnectLevelOrderSiblings solution;
    TreeNode* actual = solution.calculateTime(root);
    solution.printExpectations(10, actual->val);
}