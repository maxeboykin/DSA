/*To-Do: show various methods including sorting the strings,
 * using prime factor decomposition, and maybe just counting freq of chars
 * like a normal hash map
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <cctype>

class GroupAnagram {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
        std::vector<std::vector<std::string>> anagrams = {};
        std::unordered_map<std::string, std::vector<std::string>> sortMap;
        for(auto& str : strs){ // O(n)
            std::string key = str;
            std::sort(key.begin(), key.end());
            if(sortMap[key].size() == 0){
                sortMap[key].push_back(str); // can push here since array is initiliazed in sortMap definition
            } else {
                sortMap[key].push_back(str);
            }
        }
        for(auto& pair: sortMap){
            anagrams.push_back(pair.second);
        }
        return anagrams;
    }
    std::vector<std::vector<std::string>> calculateTime(std::vector<std::string> &strs){
        clock_t start;
        clock_t end;
        start = clock();
        std::vector<std::vector<std::string>> result = groupAnagrams(strs);
        end = clock();
        printf("Ransom Note: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(std::vector<std::vector<std::string>> expected, std::vector<std::vector<std::string>> actual){
        std::cout << "Group Anagrams: ";
        std::cout << "Expected: " << std::endl;
        printNestedArray(expected);
        std::cout << "Actual: " << std::endl;
        printNestedArray(actual);
    }
    void printNestedArray(std::vector<std::vector<std::string>> arr){
        for(auto& outerArr: arr){
            std::cout << "[";
            for(auto& val: outerArr){
                std::cout << val << " ";
            }
            std::cout << "]";
        }
        std::cout << std::endl;
    }
};


int main(){
    GroupAnagram solution;
    std::vector<std::string>foo = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> expectedResult = {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};
    std::vector<std::vector<std::string>> result = solution.calculateTime(foo);
    solution.printExpectations(expectedResult, result);
}
