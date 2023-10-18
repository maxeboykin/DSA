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
    static bool findPath(TreeNode *root, const std::vector<int>sequence) {
        int inputSize = sequence.size();
        return findPathRecursively(root, sequence, inputSize, 1);
    }
    static bool findPathRecursively(TreeNode *curNode, const std::vector<int> &sequence, int inputSize, int levelSize){
        if(curNode == nullptr){
            return false;
        }
        if(curNode->left == nullptr && curNode->right == nullptr) {
            if(sequence[levelSize-1] == curNode->val){
                return true;
            } else {
                return false;
            }
        }
        if(sequence[levelSize-1] != curNode->val){
            return false;
        }
        return findPathRecursively(curNode->left, sequence, inputSize, levelSize+1) ||
                findPathRecursively(curNode->right, sequence, inputSize, levelSize+1);
    }

    bool calculateTime(TreeNode *root, const std::vector<int>&sequence){
        clock_t start;
        clock_t end;
        start = clock();
        bool result = findPath(root, sequence);
        end = clock();
        printf("Path with Given Sequence: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(int expected, int actual){
        std::cout << "Has Path Sum: ";
        std::cout << "Expected: " << expected << std::endl;
        std::cout << "Actual: " << actual << std::endl;
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(9);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(9);
    TreePathSum solution;
    const std::vector<int>sequence1 = {1,9,9};
    bool actual = solution.calculateTime(root, sequence1);
    bool expected = true;
    solution.printExpectations(expected, actual);
    root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);
    const std::vector<int>sequence2 = {1,0,7};
    const std::vector<int>sequence3 = {1,1,6};
    bool actual2 = solution.calculateTime(root, sequence2);
    bool expected2 = false;
    solution.printExpectations(expected2, actual2);
    bool actual3 = solution.calculateTime(root, sequence3);
    bool expected3 = true;
    solution.printExpectations(expected3, actual3);
}

//The space complexity of the above algorithm will be O(N) in the worst case. This space will be used to store the recursion stack. The worst case will happen when the given tree is a linked list (i.e., every node has only one child).

