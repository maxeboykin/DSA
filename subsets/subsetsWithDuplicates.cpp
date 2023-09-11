//TO-DO This is done the iterative way. Can also do recursive way.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <cctype>

class SubsetsWithDuplicates {
public:
    std::vector<std::vector<int>> findSubsets(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> subsets;
        subsets.push_back(std::vector<int>{});
        int startIndex = 0;
        int endIndex = 0;
        for(int i = 0; i < nums.size(); i++){
            startIndex = 0;
            if (i > 0 && nums[i] == nums[i-1]){
                startIndex = endIndex + 1;
            }
            endIndex = subsets.size() -1;
            for(int j = startIndex; j <= endIndex; j++){
                std::vector<int> curSet = subsets[j];
                curSet.push_back(nums[i]);
                subsets.push_back(curSet);
            }
        }
        return subsets;
    }
    std::vector<std::vector<int>> calculateTime(std::vector<int>& nums){
        clock_t start;
        clock_t end;
        start = clock();
        std::vector<std::vector<int>> result = findSubsets(nums);
        end = clock();
        printf("Subsets With Duplicates: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(std::vector<std::vector<int>> expected, std::vector<std::vector<int>> actual){
        std::cout << "Subsets w Duplicates: ";
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
    SubsetsWithDuplicates solution;
    std::vector<int> foo = {1, 3, 3};
    std::vector<std::vector<int>> result1 = solution.calculateTime(foo);
    std::vector<std::vector<int>> expectation1 = {{}, {1}, {3}, {1,3}, {3,3}, {1,3,3}};
    solution.printExpectations(expectation1, result1);
    std::vector<int> bar = {1, 3, 5, 7, 9};
    solution.calculateTime(bar); // 39 clicks
    std::vector<int> zoo = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27};
    solution.calculateTime(zoo); // 21648 clicks!
}
