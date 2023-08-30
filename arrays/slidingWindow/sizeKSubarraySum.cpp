#include <iostream>
#include <vector>
#include <string>
#include <math.h>
/*
 * Given an array of positive numbers and a positive number 'k,'
 * find the maximum sum of any contiguous subarray of size 'k'.
 */

using namespace std;
class MaxSumSubarrayOfSizeK {
public:
    static int findMaxSumSubArray(int k, const vector<int> &arr) {
        int left = 0;
        int right = 0;
        int curSum = 0;
        int curMaxSum = - INFINITY; // somehow doesnt get changed in the second test. it keeps max of 9 from test one....
        while(right < arr.size() && right < k){  //guarding if k is greater than arr size
            curSum += arr[right];
            right++;
        }
        if(curSum > curMaxSum) curMaxSum = curSum;
        left++;
        while(right < arr.size()){
            curSum -= arr[left-1];
            curSum += arr[right];
            if(curSum > curMaxSum) curMaxSum = curSum;
            left++;
            right++;
        }
        return curMaxSum;
    }
};

int main(){
    MaxSumSubarrayOfSizeK solution;
    vector<int> foo = {2, 1, 5, 1, 3, 2};
    int k1 = 3;
    int expectedResult = 9;
    vector<int> bar = {2, 3, 4, 1, 5};
    int k2 = 2;
    int expectedResultTwo = 7;
    int resultOne = solution.findMaxSumSubArray(k1, foo);
    int resultTwo = solution.findMaxSumSubArray(k2, bar);
    cout << "findMaxSumSubArray: ";
    cout << "Expected result: " << expectedResult << " actual: " << resultOne;
    cout << endl;
    cout << "Expected result: " << expectedResultTwo << " actual: " << resultTwo;
    cout << endl;
}