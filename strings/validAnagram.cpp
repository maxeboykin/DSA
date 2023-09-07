#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
/*
 * Given an integer array nums, find the subarray
 with the largest sum, and return its sum.
 */
// TO-DO: try to do with an array instead hash in another method, compare time

class ValidAnagram {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> charFrequency;

        if(!s.size() || !t.size() || s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++){
            charFrequency[s[i]]++;
        }
        for(int j = 0; j < t.size(); j++){
            if(charFrequency[t[j]] == 0) return false;
            if(charFrequency[t[j]] == 1) {
                charFrequency.erase(t[j]);
            } else {
                charFrequency[t[j]]--;
            }
        }
         if(charFrequency.size()) return false;
         return true;
    }
    bool isAnagramTwo(std::string s, std::string t) {
        std::unordered_map<char, int> charFrequency;

        if(!s.size() || !t.size() || s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++){
            charFrequency[s[i]]++; // increment frequency of s in map
            charFrequency[t[i]]--; // decrement frequency of t in map
        }
        // check if frequency of all characters is 0
        for (const auto& [chr, freq] : charFrequency) {
            if (freq != 0) {
                return false;
            }
        }
        return true;
    }
};

int main(){
    clock_t start;
    clock_t end;
    ValidAnagram solution;
    std::string foo = "anagram";
    std::string oof = "nagaram";
    bool expectedResult = true;
    std::string bar = "rat";
    std::string rab = "car";
    bool expectedResultTwo = false;
    start = clock();
    int resultOne = solution.isAnagram(foo, oof);
    end = clock();
    printf("isAnagram: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
    start = clock();
    int resultTwo = solution.isAnagram(bar, rab);
    end = clock();
    printf("isAnagram: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);

    // trying second version to see what is faster
    start = clock();
    resultOne = solution.isAnagramTwo(foo, oof);
    end = clock();
    printf("isAnagramTwo: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
    start = clock();
    resultTwo = solution.isAnagramTwo(bar, rab);
    end = clock();
    printf("isAnagramTwo: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);


    printf("it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
    std::cout << "valid anagram: ";
    std::cout << std::endl;
    std::cout << "Expected valid anagram: " << expectedResult << " actual: " << resultOne;
    std::cout << std::endl;
    std::cout << "Expected valid anagram: " << expectedResultTwo << " actual: " << resultTwo;
    std::cout << std::endl;
}