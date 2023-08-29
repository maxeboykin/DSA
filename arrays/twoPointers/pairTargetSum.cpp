#include <iostream>
#include <vector>

/*
 * Given an array of numbers sorted in ascending order and a target sum,
 * find a pair in the array whose sum is equal to the given target.
 * Write a function to return the indices of the two numbers
 * (i.e. the pair) such that they add up to the given target.
 */

using namespace std;
class PairTargetSum {
public:
    static vector<int> search(const vector<int>& arr, int targetSum) {
        int left = 0;
        int right = arr.size() - 1;
        while(left < right){
            int curSum = arr[left] + arr[right];
            if(curSum == targetSum){
                return {left, right};
            }
            if(curSum < targetSum){
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1};
    }
};

int main(){
    PairTargetSum solution;
    vector<int> foo{1, 2, 3, 4, 6};
    int target = 6;
    vector<int> bar{2, 5, 9, 11};
    int targetTwo = 11;
    vector<int> resultOne = solution.search(foo, target);
    vector<int> resultTwo = solution.search(bar, targetTwo);
    cout << "pair target sum: ";

    for(const auto& element: resultOne) {
        cout << element << " ";
    }
    for(const auto& element: resultTwo) {
        cout << element << " ";
    }
    cout << endl;
}