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
// deque methods include push_front, push_back
class ZigzagTraversal {
public:
    std::vector<std::vector<int>> traverse(TreeNode *root) {
        std::vector<std::vector<int>> results;
        if(root == nullptr) {
            return results;
        }
        std::queue<TreeNode *> queue;
        queue.push(root);
        bool reverse = false;
        while(!queue.empty()){
            int curLevelSize = queue.size();
            //std::deque<int> curLevelValues;
            std::vector<int> curLevelValues(curLevelSize);
            for(int i = 0; i < curLevelSize; i++) {
                TreeNode *curNode = queue.front();
                queue.pop();
                if(reverse) curLevelValues[curLevelSize-1-i] = curNode->val;
                if(!reverse) curLevelValues[i] = curNode->val;
//                if(reverse) curLevelValues.push_front(curNode->val);
//                if(!reverse) curLevelValues.push_back(curNode->val);
                if(curNode->left != nullptr) queue.push(curNode->left);
                if(curNode->right != nullptr) queue.push(curNode->right);
            }
            reverse = !reverse;
            results.push_back(curLevelValues);
        }
        return results;
    }
    std::vector<std::vector<int>> calculateTime(TreeNode *root){
        clock_t start;
        clock_t end;
        start = clock();
        std::vector<std::vector<int>> result = traverse(root);
        end = clock();
        printf("Binary Tree Level Order ZigZag Traversal: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(std::vector<std::vector<int>> expected, std::vector<std::vector<int>> actual){
        std::cout << "Binary Tree Level Order Zigzag Traversal: ";
        std::cout << "Expected: " << std::endl;
        printNestedVector(expected);
        std::cout << "Actual: " << std::endl;
        printNestedVector(actual);
    }
    void printNestedVector(std::vector<std::vector<int>> arr){
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
    ZigzagTraversal solution;
    std::vector<std::vector<int>> actual = solution.calculateTime(root);
    std::vector<std::vector<int>> expected = {{12},{1,7},{9,10,5}};
    solution.printExpectations(expected, actual);

    root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    root->right->left->left = new TreeNode(20);
    root->right->left->right = new TreeNode(17);
    std::vector<std::vector<int>> actual2 = solution.calculateTime(root);
    std::vector<std::vector<int>> expected2 = {{12},{1,7},{9,10,5}, {17,20}};
    solution.printExpectations(expected2, actual2);
}