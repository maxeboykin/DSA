#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <cctype>

bool calculateTime(std::string arg, bool (*func)(std::string));

class LongestRepeatingCharReplacement {
public:
    int lengthOfLongestSubstring(std::string s, int k){
        std::unordered_map<char, int> charCount;
        int left = 0;
        int maxCurrentLetterCount = 0;
        int maxSubstringCount = 0;
        for(int right = 0; right < s.length(); right++){
            charCount[s[right]]++;
            maxCurrentLetterCount = std::max(maxCurrentLetterCount, charCount[s[right]]);

            while((right - left + 1) - maxCurrentLetterCount > k){
                left++;
                charCount[s[left-1]]--;
            }
            maxSubstringCount = std::max(maxSubstringCount, right - left + 1);
        }
        return maxSubstringCount;
    }
    int calculateTime(std::string arg, int k){
        clock_t start;
        clock_t end;
        start = clock();
        int result = lengthOfLongestSubstring(arg, k);
        end = clock();
        printf("LongestRepeatingCharReplacement: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(int expected, int actual, int expected2, int actual2, int expected3, int actual3){
        std::cout << "LongestRepeatingCharReplacement: ";
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
    LongestRepeatingCharReplacement solution;
    std::string foo = "ABAB";
    int k1 = 2;
    int expectedResult = 4;
    std::string bar = "AABABBA";
    int k2 = 1;
    int expectedResultTwo = 4;
    std::string zig = "AABCACCCC";
    int k3 = 2;
    int expectedResultThree = 7;

    int resultOne = solution.calculateTime(foo, k1);
    int resultTwo = solution.calculateTime(bar, k2);
    int resultThree = solution.calculateTime(zig, k3);
    solution.printExpectations(expectedResult, resultOne, expectedResultTwo, resultTwo, expectedResultThree, resultThree);
}
