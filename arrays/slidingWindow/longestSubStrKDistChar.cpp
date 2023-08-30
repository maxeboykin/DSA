#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
/*
 * Given a string, find the length of the longest substring in it with no more than K distinct characters.
 * You can assume that K is less than or equal to the length of the given string.
 * NOTE: HAD TO ADJUST SINCE NUMBERS CAN BE IN THE STRING SO NOW USING A HASHMAP THAN AN ALPHANUMERIC ARRAY
 */

using namespace std;
class LongestSubStrKDistChar {
public:
    static int findLength(const string &str, int k) {
        // int uniqueCount = 0;
        unordered_map<char, int> charCount;
        int curMaxLength = numeric_limits<int>::min();
        int left = 0;
        for(int right = 0; right < str.length(); right++){
//            if(charCount[str[right]] == 0){
//                uniqueCount++;
//            }
            charCount[str[right]]++;
            while(left <= right && charCount.size() > k){
                left++;
                charCount[str[left-1]]--;
                if(charCount[str[left-1]] == 0){
                    // uniqueCount--;
                    charCount.erase(str[left-1]);
                }
            }
            curMaxLength = max(curMaxLength, right - left + 1);
        }
        return curMaxLength;
    }
    static int findLengthJustAlpha(const string &str, int k) {
        int uniqueCount = 0;
        vector<int> charCount(26, 0);
        int curMaxLength = numeric_limits<int>::min();
        int left = 0;
        for(int right = 0; right < str.length(); right++){
            int charIdx = str[right] - 'a';
            if(charCount[charIdx] == 0) uniqueCount++;
            charCount[charIdx]++;
            while(left <= right && uniqueCount > k){
                left++;
                int charRemovedIdx = str[left - 1] - 'a';
                charCount[charRemovedIdx]--;
                if(charCount[charRemovedIdx] == 0) uniqueCount--;
            }
            curMaxLength = max(curMaxLength, right - left + 1);
        }
        return curMaxLength;
    }
};

int main(){
    LongestSubStrKDistChar solution;
    string foo = "araaci";
    int k1 = 2;
    int expectedResult = 4;
    string bar = "araaci";
    int k2 = 1;
    int expectedResultTwo = 2;
    string zing = "cbbebi";
    int k3 = 3;
    int expectedResultThree = 5;
    int resultOne = solution.findLength(foo, k1);
    int resultTwo = solution.findLength( bar, k2 );
    int resultThree = solution.findLength( zing, k3);
    cout << "findMaxSumSubArray: ";
    cout << "Expected result: " << expectedResult << " actual: " << resultOne;
    cout << endl;
    cout << "Expected result: " << expectedResultTwo << " actual: " << resultTwo;
    cout << endl;
    cout << "Expected result: " << expectedResultThree << " actual: " << resultThree;
    cout << endl;
}