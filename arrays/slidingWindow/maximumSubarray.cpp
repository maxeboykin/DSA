#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
/*
 * Given an integer array nums, find the subarray
 with the largest sum, and return its sum.
 */

using namespace std;
class MaximumSubarray {
public:
    int maxSubArray(const vector<int> &nums) {
        int maxSum = numeric_limits<int>::min();;
        int curSum = 0;
        int left = 0;
        // initialize left in case all are negative
        while(left < nums.size() && nums[left] < 0){
            maxSum = max(maxSum, nums[left]);
            left++;
        }

        for(int right = left; right < nums.size(); right++){
          curSum += nums[right];
          maxSum = max(curSum, maxSum);
          while(left <= right && curSum < 0){
              left++;
              curSum -= nums[left-1];
              maxSum = max(curSum, maxSum);
          }
        }
        return maxSum;
    }
};

int main(){
    MaximumSubarray solution;
    vector<int> foo = {-2,1,-3,4,-1,2,1,-5,4};
    int expectedResult = 6;
    vector<int> bar = {5,4,-1,7,8};
    int expectedResultTwo = 23;
    vector<int> zig = {-1};
    int expectedResultThree = -1;
    int resultOne = solution.maxSubArray(foo);
    int resultTwo = solution.maxSubArray(bar);
    int resultThree = solution.maxSubArray(zig);
    cout << "best Time to Buy and Sell Stock: ";
    cout << endl;
    cout << "Expected profit result: " << expectedResult << " actual: " << resultOne;
    cout << endl;
    cout << "Expected profit result: " << expectedResultTwo << " actual: " << resultTwo;
    cout << endl;
    cout << "Expected profit result: " << expectedResultThree << " actual: " << resultThree;
    cout << endl;
}