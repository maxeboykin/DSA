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
// deque methods include
class BinaryTreeLevelOrderTraversalReverse {
public:
    static std::deque<std::vector<int>> traverse(TreeNode *root) {
        std::deque<std::vector<int>> results = {};
        if(root == nullptr) {
            return results;
        }
        std::queue<TreeNode *> queue; // note to add pointer here
        queue.push(root);
        while(!queue.empty()){
           int curLevelSize = queue.size();
           std::vector<int> curLevelValues = {};
           for(int i = 0; i < curLevelSize; i++){
               TreeNode *curNode = queue.front();
               queue.pop();
               curLevelValues.push_back(curNode->val);
               if(curNode->left != nullptr) queue.push(curNode->left);
               if(curNode->right != nullptr) queue.push(curNode->right);
           }
           results.push_front(curLevelValues);
        }
        return results;
    }
    std::deque<std::vector<int>> calculateTime(TreeNode *root){
        clock_t start;
        clock_t end;
        start = clock();
        std::deque<std::vector<int>> result = traverse(root);
        end = clock();
        printf("Binary Tree Level Order Traversal: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(std::deque<std::vector<int>> expected, std::deque<std::vector<int>> actual){
        std::cout << "Binary Tree Level Order Traversal Reverse: ";
        std::cout << "Expected: " << std::endl;
        printNestedVector(expected);
        std::cout << "Actual: " << std::endl;
        printNestedVector(actual);
    }
    void printNestedVector(std::deque<std::vector<int>> arr){
        for(auto& outerArr: arr){
            std::cout << "[";
            for(auto& val: outerArr){
                std::cout << val << " ";
            }
            std::cout << "]";
        }
        std::cout << std::endl;
    }
};


int main(){
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    BinaryTreeLevelOrderTraversalReverse solution;
    std::deque<std::vector<int>> actual = solution.calculateTime(root);
    std::deque<std::vector<int>> expected = {{9,10,5},{7,1},{12}};
    solution.printExpectations(expected, actual);
}