#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>

bool calculateTime(std::string arg, bool (*func)(std::string));

class FindAllAnagramsInString {
public:
    std::vector<int> findAnagrams(std::string s, std::string p){
        std::unordered_map<char, int>original;
        std::unordered_map<char, int>current;
        std::vector<int> result = {};

        for(int i = 0; i < p.length(); i++){ /* creating original hash */
            original[p[i]]++;
        }
        int left = 0;
        for(int right = 0; right < s.length(); right++){
            current[s[right]]++;

            if((right - left + 1) > p.length()){
                left++;
                current[s[left-1]]--;
            }
            if((right - left + 1) == p.length()){ /* assess if anagram */
                int totalCurrentChars = 0; // need this to equal p.length() to ensure no other stray chars
                for (const auto& [chr, freq] : current){ /* want to do current since its O(26) and not p which is O(n)*/
                    if(original[chr] != freq) break;
                    totalCurrentChars += freq;
                }
                if(totalCurrentChars == p.length()) result.push_back(left);
            }
        }
        return result;
    }
    std::vector<int> calculateTime(std::string s, std::string p){
        clock_t start;
        clock_t end;
        start = clock();
        std::vector<int> result = findAnagrams(s, p);
        end = clock();
        printf("LongestRepeatingCharReplacement: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(std::vector<int> expected, std::vector<int> actual, std::vector<int> expected2,
                           std::vector<int> actual2){
        std::cout << "LongestRepeatingCharReplacement: ";
        std::cout << std::endl;
        int idx = 0;
        for(const auto& value: actual){
            std::cout << "Expected value: " << expected[idx] << " actual val: " << value << std::endl;
            idx++;
        }
        idx = 0;
        for(const auto& value: actual2){
            std::cout << "Expected value: " << expected2[idx] << " actual val: " << value << std::endl;
            idx++;
        }
    }
};


int main(){
    FindAllAnagramsInString solution;
    std::string foo = "cbaebabacd";
    std::string p1 = "abc";
    std::vector<int> expectedResult = {0, 6};
    std::string bar = "abab";
    std::string p2 = "ab";
    std::vector<int> expectedResultTwo = {0, 1, 2};

    std::vector<int> resultOne = solution.calculateTime(foo, p1);
    std::vector<int> resultTwo = solution.calculateTime(bar, p2);

    solution.printExpectations(expectedResult, resultOne, expectedResultTwo, resultTwo);
}
