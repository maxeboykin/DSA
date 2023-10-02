#include <iostream>
#include <vector>
#include <stack>

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
class TreePathSum{
public:
    static bool hasPathIterative(TreeNode *root, int sum) {
        if(root == nullptr) {
            return false;
        }
        int curSum = 0;
        std::stack<TreeNode*> stack = {};
        stack.push(root);
        curSum += root->val;
        while(!stack.empty()){
            TreeNode* current = stack.top();
            while(current->left != nullptr || current->right != nullptr) {
                if(current->left != nullptr) {
                    stack.push(current->left);
                    current = current->left;
                    curSum += current->val;
                } else {
                    stack.push(current->right);
                    current = current->right;
                    curSum += current->val;
                }
            }
            if(curSum == sum) return true;
            current = stack.top();
            stack.pop();
            curSum -= current->val;
        }
        return false;
    }
    static bool hasPath(TreeNode *root, int sum) {
        if(root == nullptr) {
            return false;
        }
        // base case
        if(root->left == nullptr && root->right == nullptr){
            if(root->val == sum) return true;
        }
        // recursive case
        return hasPath(root->left, sum - root->val) || hasPath(root->right, sum - root->val);
    }
    bool calculateTime(TreeNode *root, int sum){
        clock_t start;
        clock_t end;
        start = clock();
        bool result = hasPath(root, sum);
        end = clock();
        printf("Has Path Sum: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(int expected, int actual){
        std::cout << "Has Path Sum: ";
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
    TreePathSum solution;
    bool actual = solution.calculateTime(root, 23);
    bool expected = true;
    solution.printExpectations(expected, actual);
    bool actual2 = solution.calculateTime(root, 16);
    bool expected2 = false;
    solution.printExpectations(expected2, actual2);
}

//The space complexity of the above algorithm will be O(N) in the worst case. This space will be used to store the recursion stack. The worst case will happen when the given tree is a linked list (i.e., every node has only one child).

