#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <cctype>

bool calculateTime(std::string arg, bool (*func)(std::string));

class ValidAnagram {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = s.length() - 1;
        while(left < right){
            // need to check if alnum
            while(left < right && !isalnum(s[left])){
                left++;
            }
            while(left < right && !isalnum(s[right])){
                right--;
            }

            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool calculateTime(std::string arg){
        clock_t start;
        clock_t end;
        start = clock();
        bool result = isPalindrome(arg);
        end = clock();
        printf("isPalindrome: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(bool expected, bool actual, bool expected2, bool actual2, bool expected3, bool actual3){
        std::cout << "valid palindrome: ";
        std::cout << std::endl;
        std::cout << "Expected valid palindrome: " << expected << " actual: " << actual;
        std::cout << std::endl;
        std::cout << "Expected valid palindrome: " << expected2 << " actual: " << actual2;
        std::cout << std::endl;
        std::cout << "Expected valid palindrome: " << expected3 << " actual: " << actual3;
        std::cout << std::endl;
    }
};


int main(){
    ValidAnagram solution;
    std::string foo = "A man, a plan, a canal, Panama!";
    bool expectedResult = true;
    std::string bar = "Was it a car or a cat I saw?";
    bool expectedResultTwo = true;
    std::string zig = "Was it a car or a car I saw?";
    bool expectedResultThree = false;
    bool resultOne = solution.calculateTime(foo);
    bool resultTwo = solution.calculateTime(bar);
    bool resultThree = solution.calculateTime(zig);
    solution.printExpectations(expectedResult, resultOne, expectedResultTwo, resultTwo, expectedResultThree, resultThree);
}
