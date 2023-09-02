#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
/*
 * Given an integer array nums, find the subarray
 with the largest sum, and return its sum.
 */

class ValidAnagram {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> dict;


        // if dict.size() return false
    }
};

int main(){
    ValidAnagram solution;
    std::string foo = "anagram";
    std::string oof = "nagaram";
    bool expectedResult = true;
    std::string bar = "rat";
    std::string rab = "car";
    bool expectedResultTwo = false;
    int resultOne = solution.isAnagram(foo, oof);
    int resultTwo = solution.isAnagram(bar, rab);
    std::cout << "valid anagram: ";
    std::cout << std::endl;
    std::cout << "Expected valid anagram: " << expectedResult << " actual: " << resultOne;
    std::cout << std::endl;
    std::cout << "Expected valid anagram: " << expectedResultTwo << " actual: " << resultTwo;
    std::cout << std::endl;
}