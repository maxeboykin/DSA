#include <iostream>
#include <vector>
#include <algorithm>
/*
 * Given an integer array nums, find the subarray
 with the largest sum, and return its sum.
 */

class MaximumSubarray {
public:
    int maxSubArray(const std::vector<int> &nums) {
        int maxSum = std::numeric_limits<int>::min();;
        int curSum = 0;
        int left = 0;
        // initialize left in case all are negative
        while(left < nums.size() && nums[left] < 0){
            maxSum = std::max(maxSum, nums[left]);
            left++;
        }

        for(int right = left; right < nums.size(); right++){
          curSum += nums[right];
          maxSum = std::max(curSum, maxSum);
          while(left <= right && curSum < 0){
              left++;
              curSum -= nums[left-1];
              maxSum = std::max(curSum, maxSum);
          }
        }
        return maxSum;
    }
};

int main(){
    MaximumSubarray solution;
    std::vector<int> foo = {-2,1,-3,4,-1,2,1,-5,4};
    int expectedResult = 6;
    std::vector<int> bar = {5,4,-1,7,8};
    int expectedResultTwo = 23;
    std::vector<int> zig = {-1};
    int expectedResultThree = -1;
    int resultOne = solution.maxSubArray(foo);
    int resultTwo = solution.maxSubArray(bar);
    int resultThree = solution.maxSubArray(zig);
    std::cout << "best Time to Buy and Sell Stock: ";
    std::cout << std::endl;
    std::cout << "Expected profit result: " << expectedResult << " actual: " << resultOne;
    std::cout << std::endl;
    std::cout << "Expected profit result: " << expectedResultTwo << " actual: " << resultTwo;
    std::cout << std::endl;
    std::cout << "Expected profit result: " << expectedResultThree << " actual: " << resultThree;
    std::cout << std::endl;
}