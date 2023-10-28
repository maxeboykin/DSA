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
class AllPaths{
public:
     static std::vector<std::vector<int>> findPaths(TreeNode *root, int sum){
        std::vector<std::vector<int>> allPaths = {};
        static std::vector<int> curPath = {};
        getPaths(root, curPath, allPaths, sum);
        return allPaths;
    }
    static void getPaths(TreeNode* curNode, std::vector<int> &curPath, std::vector<std::vector<int>> &allPaths, int target){
        if(curNode == nullptr){
            return;
        }
        curPath.push_back(curNode->val);
        if(curNode->left == nullptr && curNode->right == nullptr){
            if(curNode->val == target){
                allPaths.push_back(curPath); // this copies all of whats in curPath so it will be an N space operation and time
            }
        } else {
            getPaths(curNode->left, curPath, allPaths, target - curNode->val);
            getPaths(curNode->right, curPath, allPaths, target - curNode->val);
        }
        // need to do this since its static;  we need to remove current node when we go up the recursive call stack
        curPath.pop_back();
    }

    std::vector<std::vector<int>> calculateTime(TreeNode *root, int sum){
        clock_t start;
        clock_t end;
        start = clock();
        std::vector<std::vector<int>> result = findPaths(root, sum);
        end = clock();
        printf("All Path Sums: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(std::vector<std::vector<int>> expected, std::vector<std::vector<int>> actual){
        std::cout << "Binary Tree Allpaths: ";
        std::cout << "Expected: " << std::endl;
        printNestedArray(expected);
        std::cout << "Actual: " << std::endl;
        printNestedArray(actual);
    }
    void printNestedArray(std::vector<std::vector<int>> arr){
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
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(7);
    AllPaths solution;
    std::vector<std::vector<int>> actual = solution.calculateTime(root, 12);
    std::vector<std::vector<int>> expected = {{1,7,4}, {1,9,2}};
    solution.printExpectations(expected, actual);

    root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    std::vector<std::vector<int>> actual2 = solution.calculateTime(root, 23);
    std::vector<std::vector<int>> expected2 = {{12,7,4}, {12,1,10}};
    solution.printExpectations(expected2, actual2);
}

//The space complexity of the above algorithm will be O(N) in the worst case. This space will be used to store the recursion stack. The worst case will happen when the given tree is a linked list (i.e., every node has only one child).

