
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <cctype>

class Subsets {
public:
    std::vector<std::vector<int>> findSubsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> subsets;
        subsets.push_back(std::vector<int>{});
        for(auto current: nums){
            int n = subsets.size(); // need this since subsets size will increase in next loop
            for(int i = 0; i < n; i++){
                std::vector<int> curSet = subsets[i];
                curSet.push_back(current);
                subsets.push_back(curSet);
            }
        }
        return subsets;
    }
    void printExpectations(std::vector<std::vector<int>> expected, std::vector<std::vector<int>> actual){
        std::cout << "Group Anagrams: ";
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
    Subsets solution;
    std::vector<int> foo = {1, 3};
    std::vector<std::vector<int>> result1 = solution.findSubsets(foo);
    std::vector<std::vector<int>> expectation1 = {{}, {1}, {5}, {3}, {1,5}, {1,3}, {5,3}, {1,5,3}};
    solution.printExpectations(expectation1, result1);
}
