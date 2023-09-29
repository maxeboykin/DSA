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
class BinaryTreeLevelOrderAverage{
public:
    std::vector<double> traverse(TreeNode *root) {
        std::vector<double> results;
        if(root == nullptr) {
            return results;
        }
        std::queue<TreeNode *> queue = {};
        queue.push(root);
        while(!queue.empty()){
            double curLevelSize = queue.size();
            double curLevelSum = 0;
            for(double i = 0; i < curLevelSize; i++) {
                TreeNode *curNode = queue.front();
                queue.pop();
                curLevelSum += curNode->val;
                if(curNode->left != nullptr) queue.push(curNode->left);
                if(curNode->right != nullptr) queue.push(curNode->right);
            }
            results.push_back(curLevelSum / curLevelSize);
        }
        return results;
    }
    std::vector<double> calculateTime(TreeNode *root){
        clock_t start;
        clock_t end;
        start = clock();
        std::vector<double> result = traverse(root);
        end = clock();
        printf("Binary Tree Level Order Averages: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(std::vector<double> expected, std::vector<double> actual){
        std::cout << "Binary Tree Level Order Averages: ";
        std::cout << "Expected: " << std::endl;
        printVector(expected);
        std::cout << "Actual: " << std::endl;
        printVector(actual);
    }
    void printVector(std::vector<double> arr){
        for(auto& val: arr){
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main(){
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    BinaryTreeLevelOrderAverage solution;
    std::vector<double> actual = solution.calculateTime(root);
    std::vector<double> expected = {12.0, 4.0, 6.0};
    solution.printExpectations(expected, actual);
}