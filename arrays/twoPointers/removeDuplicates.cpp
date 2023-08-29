#include <iostream>
#include <vector>
#include <string>
/*
 * Given an array of sorted numbers, remove all duplicate number instances
 * from it in-place, such that each element appears only once.
 * The relative order of the elements should be kept the same and you should
 * not use any extra space so that the solution has a space complexity of O(1).
 * Move all the unique elements at the beginning of the array and after
 * moving return the length of the subarray that has no duplicate in it.
 */

using namespace std;
class RemoveDuplicates {
public:
    static int remove(vector<int> &arr) {
        int right = 0;
        int left = 0;
        while(right < arr.size()) {
            if (arr[left] == arr[right]) {
                right++;
            } else { // case when arr[left] != arr[right]
                left++;
                arr[left] = arr[right];
            }
        }
        return left + 1;
    }
};

int main(){
    RemoveDuplicates solution;
    vector<int> foo = {2, 3, 3, 3, 6, 9, 9};
    int expectedResult = 4;
    vector<int> bar = {2, 2, 2, 11};
    int expectedResultTwo = 2;
    int resultOne = solution.remove(foo);
    int resultTwo = solution.remove(bar);
    cout << "remove duplicates in place: ";
    cout << "Expected result: " << expectedResult << " actual: " << resultOne;
    cout << endl;
    cout << "Expected result: " << expectedResultTwo << " actual: " << resultTwo;
    cout << endl;
}