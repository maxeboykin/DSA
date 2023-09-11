#include <iostream>
#include <vector>
#include <queue>

/*
 * TODO: learn Cpp Queues since they should be used here
 * could not code out so really study this and subsets
 */

class Combinations {
public:
    std::vector<std::vector<int>> findPermutations(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::queue<std::vector<int>> permutations;
        permutations.push(std::vector<int>{});
        for (auto currentNumber : nums) {
            int n = permutations.size();
            for(int i = 0; i < n; i++){
                std::vector<int> oldPermutation = permutations.front();
                permutations.pop(); // removes first element in queue
                for(int j = 0; j<= oldPermutation.size(); j++){
                    std::vector<int> newPermutation({oldPermutation});
                    // insert element at a current position
                    newPermutation.insert(newPermutation.begin() + j, currentNumber);
                    if(newPermutation.size() == nums.size()){
                        result.push_back(newPermutation);
                    } else {
                        permutations.push(newPermutation);
                    }
                }
            }
        }
        return result;
    }
    std::vector<std::vector<int>> calculateTime(std::vector<int>& nums){
        clock_t start;
        clock_t end;
        start = clock();
        std::vector<std::vector<int>> result = findPermutations(nums);
        end = clock();
        printf("Permutations: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(std::vector<std::vector<int>> expected, std::vector<std::vector<int>> actual){
        std::cout << "Permutations: ";
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
    Combinations solution;
    std::vector<int> foo = {1, 3, 5};
    std::vector<std::vector<int>> result1 = solution.calculateTime(foo);
    std::vector<std::vector<int>> expectation1 = {{1,3,5}, {1,5,3}, {3,1,5}, {3,5,1}, {5,1,3}, {5,3,1}};
    solution.printExpectations(expectation1, result1);
//    std::vector<int> bar = {1, 3, 5, 7, 9};
//    solution.calculateTime(bar); // 38 clicks
//    std::vector<int> zoo = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27};
//    solution.calculateTime(zoo); // 22346 clicks!
}
