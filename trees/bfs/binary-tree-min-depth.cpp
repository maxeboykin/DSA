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
class BinaryTreeLevelOrderMinDepth{
public:
    int findDepth(TreeNode *root) {
        std::vector<double> results;
        if(root == nullptr) {
            return 0;
        }
        std::queue<TreeNode *>queue = {};
        int currentHeight = 1;
        queue.push(root);
        while(!queue.empty()){
            int curLevelSize = queue.size();
            for(int i = 0; i < curLevelSize; i++){
                TreeNode *currentNode = queue.front();
                queue.pop();
                if(currentNode->left == nullptr && currentNode->right == nullptr) return currentHeight;
                if(currentNode->left != nullptr) queue.push(currentNode->left);
                if(currentNode->right != nullptr) queue.push(currentNode->right);
            }
            currentHeight++;
        }
    }
    int calculateTime(TreeNode *root){
        clock_t start;
        clock_t end;
        start = clock();
        int result = findDepth(root);
        end = clock();
        printf("Binary Tree Level Order Averages: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(int expected, int actual){
        std::cout << "Binary Tree Level Order Min Depth: ";
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
    root->right->left->left = new TreeNode(11);
    root->right->right = new TreeNode(5);
    BinaryTreeLevelOrderMinDepth solution;
    int actual = solution.calculateTime(root);
    int expected = 3;
    solution.printExpectations(expected, actual);
}