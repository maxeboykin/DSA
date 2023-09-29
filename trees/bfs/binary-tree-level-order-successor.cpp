#include <iostream>
#include <vector>
#include <queue>

class TreeNode {
public:
    int val = 0;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

// queue methods include empty, size, front, back, push, pop
class BinaryTreeLeverOrderSuccessor{
public:
    static TreeNode* findSuccessor(TreeNode *root, int key) {
        if(root == nullptr) {
            return nullptr;
        }
        std::queue<TreeNode *>queue = {};
        queue.push(root);
        while(!queue.empty()){
            TreeNode* currentNode = queue.front();
            queue.pop();
            if(currentNode->left != nullptr) queue.push(currentNode->left);
            if(currentNode->right != nullptr) queue.push(currentNode->right);
            if(currentNode->val == key){
                break;
            }
        }
        return queue.front();
    }
    static TreeNode* findSuccessorOne(TreeNode *root, int key) {
        if(root == nullptr) {
            return nullptr;
        }
        std::queue<TreeNode *>queue = {};
        queue.push(root);
        bool foundKey = false;
        while(!queue.empty()){
            int curLevelSize = queue.size();
            for(int i = 0; i < curLevelSize; i++) {
                TreeNode* currentNode = queue.front();
                queue.pop();
                if(foundKey) return currentNode;
                if(currentNode->val == key) foundKey = true;
                if(currentNode->left != nullptr) queue.push(currentNode->left);
                if(currentNode->right != nullptr) queue.push(currentNode->right);
            }
        }
        return nullptr;
    }
    static TreeNode* calculateTime(TreeNode *root, int key){
        clock_t start;
        clock_t end;
        start = clock();
        TreeNode* result = findSuccessor(root, key);
        end = clock();
        printf("Level Order Successor: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    static void printExpectations(int expected, int actual){
        std::cout << "Level Order Successor: ";
        std::cout << "Expected: " << expected << std::endl;
        std::cout << "Actual: " << actual << std::endl;
    }
};

int main(){
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    BinaryTreeLeverOrderSuccessor solution;
    TreeNode* actual = solution.calculateTime(root, 9);
    solution.printExpectations(10, actual->val);
}