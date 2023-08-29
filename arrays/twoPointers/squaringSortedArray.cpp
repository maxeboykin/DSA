#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> // abs
/*
 Given a sorted array, create a new array containing squares of all the numbers of the input array in the sorted order.
 */

using namespace std;
class SquaringSortedArray {
public:
    static vector<int> makeSquares(const vector<int> &arr) {
        int n = arr.size();
        vector<int> squares(n);
        int left = -1;
        int right = 0;
        int curIdx = 0;
        while(right < n && arr[right] < 0){
            right++;
        }
        if(right > 0) left = right - 1; // guarding against if all values are >=0
        // now right should be at least positive or zero val
        while(left >= 0 && right < n){
            if(abs(arr[left]) > abs(arr[right])){
                squares[curIdx] = abs(arr[right]) * abs(arr[right]);
                curIdx++;
                right++;
            } else {
                squares[curIdx] = abs(arr[left]) * abs(arr[left]);
                curIdx++;
                left--;
            }
        }
        while(left >= 0){
            squares[curIdx] = abs(arr[left]) * abs(arr[left]);
            curIdx++;
            left--;
        }
        while(right < n){
            squares[curIdx] = abs(arr[right]) * abs(arr[right]);
            curIdx++;
            right++;
        }
        return squares;
    }
};

int main(){
    SquaringSortedArray solution;
    vector<int> foo = {-2, -1, 0, 2, 3};
    vector<int> expectedOutput = {0, 1, 4, 4, 9};
    vector<int> bar = {-3, -1, 0, 1, 2};
    vector<int> expectedOutput2 = {0, 1, 1, 4, 9};
    vector<int> resultOne = solution.makeSquares(foo);
    vector<int> resultTwo = solution.makeSquares(bar);
    cout << "remove duplicates in place: ";
    int idx = 0;
    for(const auto& value: resultOne){
            cout << "Expected value: " << expectedOutput[idx] << " actual val: " << value << endl;
            idx++;
        }
    idx = 0;
    for(const auto& value: resultTwo){
            cout << "Expected value: " << expectedOutput2[idx] << " actual val: " << value << endl;
            idx++;
        }
}