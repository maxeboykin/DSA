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

class CountPathsForSum{
public:
     static int countPaths(TreeNode *root, int S){
        std::vector<int> currentPath;
        return countPathsRecursive(root, S, currentPath);
    }
    static int countPathsRecursive(TreeNode* curNode, int S, std::vector<int> &currentPath){
        if(curNode == nullptr){
            return 0;
        }
        currentPath.push_back(curNode->val);
        int pathCount = 0;
        double pathSum = 0;
        for(std::vector<int>::reverse_iterator itr = currentPath.rbegin(); itr != currentPath.rend(); itr++){
            pathSum += *itr;
            if(pathSum == S){
                pathCount++;
            }
        }
        pathCount += countPathsRecursive(curNode->left, S, currentPath);
        pathCount += countPathsRecursive(curNode->right, S, currentPath);
        currentPath.pop_back();
        return pathCount;
    }

    static int countPathsPrefix(TreeNode *root, int S){
         std::unordered_map<int, int>map = {};
         return countPathsPrefixSum(root, S, map, 0);
     }

    static int countPathsPrefixSum(TreeNode* curNode, int targetSum, std::unordered_map<int,int>map, int currentPathSum) {
         if(curNode == nullptr) {
             return 0;
         }
         int pathCount = 0;
         currentPathSum += curNode->val;
         if(currentPathSum == targetSum){
             pathCount++;
         }
         if(map.find(currentPathSum - targetSum) != map.end()){
             pathCount += map[currentPathSum-targetSum];
         }
         map[currentPathSum]++;
         pathCount += countPathsPrefixSum(curNode->left, targetSum, map, currentPathSum);
         pathCount += countPathsPrefixSum(curNode->right, targetSum, map, currentPathSum);

         map[currentPathSum]--;
         return pathCount;
     }

    int calculateTime(TreeNode *root, int target){
        clock_t start;
        clock_t end;
        start = clock();
        int result = countPaths(root, target);
        end = clock();
        printf("Count of Path Numbers: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    int calculateTimePrefix(TreeNode *root, int target){
        clock_t start;
        clock_t end;
        start = clock();
        int result = countPathsPrefix(root, target);
        end = clock();
        printf("Count of Path Numbers (Prefix): it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(int expected, int actual){
        std::cout << "Count of Path Numbers: ";
        std::cout << "Expected: " << expected << std::endl;
        std::cout << "Actual: " << actual << std::endl;
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(3);
    CountPathsForSum solution;
    int actual = solution.calculateTime(root, 12);
    int expected = 3;
    solution.printExpectations(expected, actual);

    root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    int actual2 = solution.calculateTime(root, 11);
    int expected2 = 2;
    solution.printExpectations(expected2, actual2);


    root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(3);
    actual = solution.calculateTimePrefix(root, 12);
    expected = 3;
    solution.printExpectations(expected, actual);

    root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    actual2 = solution.calculateTimePrefix(root, 11);
    expected2 = 2;
    solution.printExpectations(expected2, actual2);


}
