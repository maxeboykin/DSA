
#include <iostream>
#include <vector>

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
    std::vector<std::vector<int>> calculateTime(std::vector<int>& nums){
        clock_t start;
        clock_t end;
        start = clock();
        std::vector<std::vector<int>> result = findSubsets(nums);
        end = clock();
        printf("Subsets: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(std::vector<std::vector<int>> expected, std::vector<std::vector<int>> actual){
        std::cout << "Subsets: ";
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
    std::vector<std::vector<int>> result1 = solution.calculateTime(foo);
    std::vector<std::vector<int>> expectation1 = {{}, {1}, {5}, {3}, {1,5}, {1,3}, {5,3}, {1,5,3}};
    solution.printExpectations(expectation1, result1);
    std::vector<int> bar = {1, 3, 5, 7, 9};
    solution.calculateTime(bar); // 38 clicks
    std::vector<int> zoo = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27};
    solution.calculateTime(zoo); // 22346 clicks!
}
