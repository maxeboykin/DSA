#include <iostream>
#include <vector>
#include <algorithm>
/*
 * Given an integer array nums, find the subarray
 with the largest sum, and return its sum.
 */

class MaximumProductSubarray {
public:
    int maxProduct(const std::vector<int> &nums) {
        if(nums.size() < 1) return -1;
        int left = 0;
        int maxProduct = std::numeric_limits<int>::min();
        int curProduct = 1;
        int lastZeroIndex;
        bool ifZero = false;
        for(int right = 0; right < nums.size(); right++){
            curProduct = nums[right] * curProduct;
            maxProduct = std::max(curProduct, maxProduct);
            if(nums[right] == 0){
                ifZero = true;
                lastZeroIndex = right;
                curProduct = 1; // thinK!!!
            }
        }
        // if there is a zero and if there isnt a zero
        ifZero ? left = lastZeroIndex + 1 : left = 0;
        for( ; left < nums.size(); left++){
            curProduct *=
        }

        return maxProduct;
    }
};

int main(){
    MaximumProductSubarray solution;
    std::vector<int> foo = {2, 3, -2, 4};
    int expectedResult = 6;
    std::vector<int> bar = {-2, 0, -1};
    int expectedResultTwo = 0;
    std::vector<int> zig = {2,-5,-2,-4,3};
    int expectedResultThree = 24;
    // int resultOne = solution.maxProduct(foo);
    // int resultTwo = solution.maxProduct(bar);
    int resultThree = solution.maxProduct(zig);
    std::cout << "max product: ";
    std::cout << std::endl;
//    std::cout << "Expected max product: " << expectedResult << " actual: " << resultOne;
//    std::cout << std::endl;
//    std::cout << "Expected max product: " << expectedResultTwo << " actual: " << resultTwo;
//    std::cout << std::endl;
    std::cout << "Expected max product: " << expectedResultThree << " actual: " << resultThree;
    std::cout << std::endl;
}