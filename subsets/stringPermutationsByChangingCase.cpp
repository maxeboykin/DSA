#include <iostream>
#include <vector>
#include <queue>
#include <ctype.h>
#include <stdio.h>

class StringPermutationsByCase {
public:
    std::vector<std::string> findPermutations(std::string &s) {
        std::queue<std::string> permutations = {};
        permutations.push("");
        std::vector<std::string> results = {};
        for(auto currentChar: s){
            int n = permutations.size();
            for(int i = 0; i < n; i++){
                std::string oldPermutation = permutations.front();
                permutations.pop();
                bool isStrAlpha;
                isStrAlpha = isalpha(currentChar);
                std::string newPermutation = oldPermutation;
                if(isStrAlpha){
                    newPermutation.push_back(tolower(currentChar));
                    permutations.push(newPermutation);
                    std::string newUpperPermutation = oldPermutation; //not sure if this is the best time, it may be O(N) to insert at end
                    newUpperPermutation.push_back(toupper(currentChar));
                    permutations.push(newUpperPermutation);
                    if(newPermutation.length() == s.length()){
                        results.push_back(newPermutation);
                        results.push_back(newUpperPermutation);
                    }
                } else {
                    newPermutation.push_back(currentChar);
                    permutations.push(newPermutation);
                    if(newPermutation.length() == s.length()){
                        results.push_back(newPermutation);
                    }
                }
            }
        }
        return results;
    }
    std::vector<std::string> calculateTime(std::string str){
        clock_t start;
        clock_t end;
        start = clock();
        std::vector<std::string> result = findPermutations(str);
        end = clock();
        printf("Permutations: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(std::vector<std::string> expected, std::vector<std::string> actual){
        std::cout << "Permutations: ";
        std::cout << "Expected: " << std::endl;
        printNestedString(expected);
        std::cout << "Actual: " << std::endl;
        printNestedString(actual);
    }
    void printNestedString(std::vector<std::string> arr){
        for(auto& str: arr){
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
};

int main(){
    StringPermutationsByCase solution;
    std::string foo = "ad52";
    std::vector<std::string> result1 = solution.calculateTime(foo);
    std::vector<std::string> expectation1 = {"ad52", "Ad52", "aD52", "AD52"};
    solution.printExpectations(expectation1, result1);
//    std::vector<int> bar = {1, 3, 5, 7, 9};
//    solution.calculateTime(bar); // 38 clicks
//    std::vector<int> zoo = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27};
//    solution.calculateTime(zoo); // 22346 clicks!
}
