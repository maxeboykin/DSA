#include <iostream>
#include <vector>

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
class SumOfAllPaths{
public:
     static int findSumOfPathNumbers(TreeNode *root){
        static int curSum = 0;
        int total = 0;
         getSumRecursive(root, curSum, total);
        return total;
    }
    static void getSumRecursive(TreeNode* curNode, int &curSum, int &total){
        if(curNode == nullptr){
            return;
        }
        curSum = (curSum * 10) + curNode->val;
        if(curNode->left == nullptr && curNode->right == nullptr){
            total += curSum;
        } else {
            getSumRecursive(curNode->left, curSum, total);
            getSumRecursive(curNode->right, curSum, total);
        }
        curSum = curSum / 10;
    }

    int calculateTime(TreeNode *root){
        clock_t start;
        clock_t end;
        start = clock();
        int result = findSumOfPathNumbers(root);
        end = clock();
        printf("Sum of Path Numbers: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(int expected, int actual){
        std::cout << "Sum of Path Numbers: ";
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
    SumOfAllPaths solution;
    int actual = solution.calculateTime(root);
    int expected = 408;
    solution.printExpectations(expected, actual);

    root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);
    int actual2 = solution.calculateTime(root);
    int expected2 = 332;
    solution.printExpectations(expected2, actual2);
}
