#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <cctype>

class FirstMissingPositive {
public:
    bool firstMissingPositive(std::vector<int>& nums) {
      for(int i = 0; i < nums.size(); i++){
          int n = nums.size();
          while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] -1]){
              std::swap(nums[i], nums[nums[i] -1]);
          }
      }
      for(int i = 0; i < nums.size(); i++){
          if(nums[i] != i + 1){
              return i + 1;
          }
      }
      return nums.size() + 1;
    }
    bool calculateTime(std::vector<int>&nums){
        clock_t start;
        clock_t end;
        start = clock();
        bool result = firstMissingPositive(nums);
        end = clock();
        printf("First Missing Positive: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(int expected, int actual, int expected2, int actual2, int expected3, int actual3){
        std::cout << "First Missing Positive: ";
        std::cout << std::endl;
        std::cout << "Expected: " << expected << " actual: " << actual;
        std::cout << std::endl;
        std::cout << "Expected: " << expected2 << " actual: " << actual2;
        std::cout << std::endl;
        std::cout << "Expected: " << expected3 << " actual: " << actual3;
        std::cout << std::endl;
    }
};


int main(){
    FirstMissingPositive solution;
    std::vector<int> foo = {1, 2, 0};
    int expectedResult = 3;
    std::vector<int> bar = {3, 4, -1, 1};
    int expectedResultTwo = 2;
    std::vector<int> zig = {7, 8, 9, 11, 12};
    int expectedResultThree = 1;
    int resultTwo = solution.calculateTime(bar);
    int resultOne = solution.calculateTime(foo);
    int resultThree = solution.calculateTime(zig);
    solution.printExpectations(expectedResult, resultOne, expectedResultTwo, resultTwo, expectedResultThree, resultThree);
}
