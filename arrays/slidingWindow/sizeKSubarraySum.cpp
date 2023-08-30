#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
/*
 * Given an array of positive integers and a number ‘S,’ find the length of the
 * smallest contiguous subarray whose sum is greater than or equal to 'S'.
 * Return 0 if no such subarray exists.
 */

using namespace std;
class SmallestSubarrayWithGreaterSum {
public:
    static int findMinSubArray(int S, const vector<int> &arr) {
        int minWindowSize = numeric_limits<int>::max();
        int curWindowSum = 0;
        int left = 0;
        // set first minWindowSize
        for(int right = 0;right < arr.size(); right++){
            curWindowSum += arr[right];
            while(left <= right && curWindowSum >= S){
                if(left == right) return 1; // edge case of one element >= S. automatically return 1 since that is the smallest
                minWindowSize = min(minWindowSize, right - left + 1);
                left++;
                curWindowSum -= arr[left - 1];
            }
        }
        return minWindowSize == numeric_limits<int>::max() ? 0 : minWindowSize;
    }
};

int main(){
    SmallestSubarrayWithGreaterSum solution;
    vector<int> foo = {2, 1, 5, 2, 3, 2};
    int s1 = 7;
    int expectedResult = 2;
    vector<int> bar = {2, 1, 5, 2, 8};
    int s2 = 7;
    int expectedResultTwo = 1;
    vector<int> zing = {3, 4, 1, 1, 6};
    int s3 = 8;
    int expectedResultThree = 3;
    int resultOne = solution.findMinSubArray(s1, foo);
    int resultTwo = solution.findMinSubArray(s2, bar);
    int resultThree = solution.findMinSubArray(s3, zing);
    cout << "findMaxSumSubArray: ";
    cout << "Expected result: " << expectedResult << " actual: " << resultOne;
    cout << endl;
    cout << "Expected result: " << expectedResultTwo << " actual: " << resultTwo;
    cout << endl;
    cout << "Expected result: " << expectedResultThree << " actual: " << resultThree;
    cout << endl;
}