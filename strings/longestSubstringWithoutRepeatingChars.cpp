#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <cctype>

bool calculateTime(std::string arg, bool (*func)(std::string));

class LongestSubstringWithoutRepeatingChars {
public:
    int lengthOfLongestSubstring(std::string s){
        int maxLength = 0;
        std::unordered_map<char, int> charCount;
        int left = 0;
        for(int right = 0; right < s.length(); right++){
            charCount[s[right]]++;

            while(left <= right && charCount[s[right]] > 1){
                left++;
                charCount[s[left-1]]--;
            }
            maxLength = std::max(maxLength, right - left + 1);
        }
        return maxLength;
    }
    int calculateTime(std::string arg){
        clock_t start;
        clock_t end;
        start = clock();
        int result = lengthOfLongestSubstring(arg);
        end = clock();
        printf("longestSubstringWithoutRepeatingChars: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(int expected, int actual, int expected2, int actual2, int expected3, int actual3){
        std::cout << "longestSubstringWithoutRepeatingChars: ";
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
    LongestSubstringWithoutRepeatingChars solution;
    std::string foo = "abcabcbb";
    int expectedResult = 3;
    std::string bar = "bbbbb";
    int expectedResultTwo = 1;
    std::string zig = "pwwkew";
    int expectedResultThree = 3;
    int resultOne = solution.calculateTime(foo);
    int resultTwo = solution.calculateTime(bar);
    int resultThree = solution.calculateTime(zig);
    solution.printExpectations(expectedResult, resultOne, expectedResultTwo, resultTwo, expectedResultThree, resultThree);
}
